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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = new ListNode();
        ListNode *prev = newHead;
        ListNode * trav = head->next;
        while(trav->next){
            if(trav->val != 0){
                prev->val += trav->val;
            }
            else{
                prev->next = new ListNode();
                prev = prev->next;
            }
            trav = trav->next;
        }
        return newHead;
    }
};