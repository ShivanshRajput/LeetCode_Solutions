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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> ans(m , vector<int>(n,-1));
        int left = 0 , right = n-1 , up = 0 , down = m-1;
        ListNode * temp = head;
        while(left<=right && up<=down){
            for(int i=left;i<=right && temp;i++){
                ans[up][i] = temp->val;
                temp = temp->next;
            } 
            up++;
            for(int j=up;j<=down && temp;j++){
                ans[j][right] = temp->val;
                temp = temp->next;
            }    
            right --;
            for(int i=right;i>=left && temp;i--){
                ans[down][i] = temp->val;
                temp = temp->next;
            }  
            down--;
            for(int j=down;j>=up && temp;j--){
                ans[j][left] = temp->val;
                temp = temp->next;
            }    
            left++;
        }
        return ans;
    }
};