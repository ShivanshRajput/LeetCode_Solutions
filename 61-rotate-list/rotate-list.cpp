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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr) return head;
        int length = 0;
        ListNode * move = head;
        while(move != nullptr){
            length++;
            move = move->next;
        }
        int steps = length - (k%length)-1;
        move = head;
        while(steps--){
            move = move->next;
        }
        if(move->next == nullptr) return head;
        ListNode * newHead = move -> next;
        move->next = nullptr;
        ListNode * join = newHead;
        while(join->next != nullptr){
            join = join->next;
        }
        join->next = head;
        return newHead;
    }
};