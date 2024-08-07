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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode * move1 = l1;
        ListNode * move2 = l2;
        int carry = 0;
        ListNode * dummy = new ListNode();
        ListNode * curr = dummy;
        while(move1!=nullptr and move2!=nullptr){
            ListNode * temp = new ListNode((move1->val + move2->val + carry)%10);
            carry = (move1->val + move2->val + carry)/10;
            curr->next = temp;
            curr = temp;
            move1=move1->next;
            move2=move2->next;
        }  
        while(move1!=nullptr){
            ListNode * temp = new ListNode((move1->val + carry)%10);
            carry = (move1->val + carry)/10;
            curr->next = temp;
            curr = temp;
            move1=move1->next;
        }
        while(move2!=nullptr){
            ListNode * temp = new ListNode((move2->val + carry)%10);
            carry = (move2->val + carry)/10;
            curr->next = temp;
            curr = temp;
            move2=move2->next;
        }
        if(carry){
            curr->next = new ListNode(1);
        }
        ListNode * result = dummy->next;
        delete(dummy);
        return result;
    }
};