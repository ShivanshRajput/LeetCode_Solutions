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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next->next!=nullptr and fast->next->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * delNode = slow->next;
        slow->next = delNode->next;
        delete(delNode);
        return head;
    }
};