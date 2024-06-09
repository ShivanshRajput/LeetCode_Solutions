/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        priority_queue<pair<int , ListNode*> , vector<pair<int , ListNode*>> , greater<pair<int , ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push({lists[i]->val , lists[i]});
        }
        ListNode * dummyHead = new ListNode(-1);
        ListNode * move = dummyHead;
        while(!pq.empty()){
            move->next = pq.top().second;
            move = move->next;
            pq.pop();
            if(move && move->next) pq.push({move->next->val , move->next});
        }
        return dummyHead->next;
    }
};