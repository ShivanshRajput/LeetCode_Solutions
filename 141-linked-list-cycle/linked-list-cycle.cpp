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
    bool hasCycle(ListNode *head) {\
        if(head == nullptr or head->next == nullptr) return false;
        unordered_set<ListNode*> st;
        ListNode* move = head;
        while(move != nullptr){
            st.insert(move);
            move = move->next;
            if(st.find(move)!=st.end()){
                return true;
            }
        }
        return false;
    }
};