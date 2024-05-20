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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode * oddHead = head;
        ListNode * evenHead = head->next;
        ListNode * oddCurr = oddHead;
        ListNode * evenCurr = evenHead;
        while(oddCurr->next!=nullptr and evenCurr->next!=nullptr){
            oddCurr->next = oddCurr->next->next;
            evenCurr->next = evenCurr->next->next;
            oddCurr = oddCurr->next;
            evenCurr = evenCurr->next;
        }
        oddCurr->next = evenHead;
        return oddHead;
    }
};