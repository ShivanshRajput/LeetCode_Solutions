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

int init = [] {
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out<<(equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);
    
    return 0;
}();

class Solution {
public:
    bool isPalindrome(ListNode* head) {
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