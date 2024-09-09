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
            if(temp==nullptr) break;
            for(int i=left;i<=right;i++){
                ans[up][i] = temp->val;
                temp = temp->next;
                if(temp==nullptr) break;
            } 
            if(temp==nullptr) break; 
            up++;
            for(int j=up;j<=down;j++){
                ans[j][right] = temp->val;
                temp = temp->next;
                if(temp==nullptr) break;
            }    
            if(temp==nullptr) break;
            right --;
            for(int i=right;i>=left;i--){
                ans[down][i] = temp->val;
                temp = temp->next;
                if(temp==nullptr) break;
            }  
            if(temp==nullptr) break;
            down--;
            for(int j=down;j>=up;j--){
                ans[j][left] = temp->val;
                temp = temp->next;
                if(temp==nullptr) break;
            }    
            
            left++;
        }
        return ans;
    }
};