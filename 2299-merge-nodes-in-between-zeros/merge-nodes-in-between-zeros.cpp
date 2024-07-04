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
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        ListNode * modify = head->next;
        ListNode * trav = modify;
        while(trav){
            int sum = 0;
            while(trav->val != 0){
                sum+=trav->val;
                trav = trav->next;
            }
            modify->val = sum;
            modify->next = trav->next;
            modify = modify->next;
            trav = trav->next;
        }
        return head->next;
    }
};