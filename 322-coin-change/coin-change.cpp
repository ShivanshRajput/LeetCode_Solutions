class Solution {
public:

    int count(int idx , int amt , vector<int>coins , vector<vector<int>> &dp){
        if(idx==0){
            if(amt%coins[idx]==0) return amt/coins[idx]; 
            return 1e5;
        }
        if(dp[idx][amt]!= -1) return dp[idx][amt];
        int not_pick = count(idx-1 , amt , coins ,dp);
        int pick = 1e5;
        if(coins[idx]<=amt){
            pick = 1 + count(idx , amt-coins[idx] , coins ,dp);
        }
        return dp[idx][amt] = min(pick , not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1 , -1));
        int ans = count(n-1 , amount , coins ,dp);
        if(ans>=1e5) return -1;
        return ans;
    }
};