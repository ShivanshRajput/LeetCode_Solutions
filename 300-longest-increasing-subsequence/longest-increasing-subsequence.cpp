class Solution {
public:
    int len(int idx , int last_idx , vector<int> &arr , int n , vector<vector<int>>&dp){
        if(idx<0) return 0;
        if(dp[idx][last_idx] != -1) return dp[idx][last_idx];
        if(last_idx==n or arr[idx]<arr[last_idx]){
            return dp[idx][last_idx] = max(1 + len(idx-1, idx, arr , n,dp) , 0 + len(idx-1, last_idx, arr , n,dp));
        }
        else{
            return dp[idx][last_idx] = len(idx-1, last_idx, arr , n,dp);
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1 , -1));
        return len(n-1 , n , nums , n ,dp);
    }
};