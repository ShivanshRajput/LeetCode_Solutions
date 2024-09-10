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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if(head->next==nullptr) return head;
        ListNode* low = head;
        ListNode* high = head->next;
        while(high){
            ListNode* mid = new ListNode(__gcd(high->val , low->val));
            mid->next = high;
            low->next = mid;
            low = high;
            high = high->next;
        }
        return head;
    }
};