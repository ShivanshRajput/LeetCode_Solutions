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
    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ls;
        while(head){
            ls.push_back(head->val);
            head = head->next;
        }
        int low = 0 , high = ls.size()-1 ; 
        while(low<=high){
            if(ls[low]==ls[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};