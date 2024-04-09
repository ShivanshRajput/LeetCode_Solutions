class Solution {
public:
    int solve(int l , int h, vector<int>&cuts , vector<vector<int>> &dp){
        if(l>h) return 0;
        int mini = 1e8;
        if(dp[l][h] != -1) return dp[l][h];
        for(int k=l;k<=h;k++){
            int left_cost = solve(l, k-1, cuts,dp);
            int right_cost = solve(k+1, h, cuts,dp);
            int cost = (cuts[h+1] - cuts[l-1]) + left_cost + right_cost;
            mini = min(mini , cost);
        }
        return dp[l][h] = (int)mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size() , vector<int>(cuts.size(),-1));
        return solve(1 , cuts.size()-2 , cuts , dp);
    }
};