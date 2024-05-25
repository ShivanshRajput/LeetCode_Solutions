/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool loop = false;
        while(fast != nullptr and fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                loop = true;
                break;
            }
        }
        if(loop == false){
            return nullptr;
        }
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};