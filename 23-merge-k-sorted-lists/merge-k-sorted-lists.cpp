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
    ListNode *merge2list(ListNode *l1 , ListNode *l2){
        ListNode * dummyHead = new ListNode(-1);
        ListNode * move = dummyHead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                move->next = l1;
                l1 = l1->next;
                move = move->next;
            }   
            else{
                move->next = l2;
                l2 = l2->next;
                move = move->next;
            }
        }
        if(l1){
            move->next = l1;
        }
        else{
            move->next = l2;
        }
        return dummyHead -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode * newHead = lists[0];
        for(int i=1;i<lists.size();i++){
            newHead = merge2list(newHead , lists[i]);
        }
        return newHead;
    }
};