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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head->next==nullptr) return head;
        ListNode * last = reverseList(head->next);
        ListNode * ahead = head->next;
        ahead->next = head;
        head->next = nullptr;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr and fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;
    }
};