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
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        if(head==nullptr or head->next==  nullptr) return head;
        ListNode * slow = nullptr;
        ListNode * fast = head;
        while(fast != nullptr){
            ListNode * temp = slow;
            slow = fast;
            fast = fast->next;
            slow->next = temp;
        }
        return slow;
    }
};