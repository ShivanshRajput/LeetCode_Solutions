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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * move = headA;
        int lenA=0;
        while(move != NULL){
            lenA++;
            move = move->next;
        }
        int lenB=0;
        move = headB;
        while(move != NULL){
            lenB++;
            move = move->next;
        }
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        while(lenA>lenB){
            l1 = l1->next;
            lenA--;
        }
        while(lenA<lenB){
            l2 = l2->next;
            lenB--;
        }
        while(l1 != NULL){
            if(l1 == l2){
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return NULL;
    }
};