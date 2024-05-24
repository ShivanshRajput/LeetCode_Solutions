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
    ListNode *detectCycle(ListNode *head) {
        ListNode* move = head;
        unordered_set<ListNode*> st;
        while(move != nullptr){
            st.insert(move);
            move = move->next;
            if(st.find(move)!=st.end()){
                return move;
            }
        }
        return nullptr;
    }
};