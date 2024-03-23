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
    void reorderList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while(slow){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *firsthalf = head;
        ListNode *secondhalf = prev;
        while(secondhalf->next){
            next = firsthalf->next;
            prev = secondhalf->next;
            firsthalf->next = secondhalf;
            secondhalf->next = next;
            firsthalf = next;
            secondhalf = prev;
        }
    }
};