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
        unordered_set<ListNode*> st;
        ListNode * move=headA;
        while(move != NULL){
            st.insert(move);
            move=move->next;
        }
        move = headB;
        while(move!=NULL){
            if(st.find(move)!=st.end()){
                return move;
            }
            move = move->next;
        }
        return NULL;
    }
};