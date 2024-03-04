class Solution {
public:
    int earn(int idx , int buy , vector<int>&prices , int n , vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-prices[idx] + earn(idx+1, 0, prices, n,dp) , 0 + earn(idx+1, 1, prices, n,dp));
        }
        else{
            return dp[idx][buy] = max(+prices[idx] + earn(idx+2, 1, prices, n,dp) , 0 + earn(idx+1, 0, prices, n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return earn(0,1,prices,n,dp);
    }
};