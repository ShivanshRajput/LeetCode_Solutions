class Solution {
public:
    int coins(int i , int j , vector<int>&arr , vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxpoints = INT_MIN;
        for(int k=i;k<=j;k++){ // we are following to burst from last .. watch strivers video
            int points=arr[i-1]*arr[k]*arr[j+1];
            points+=coins(i , k-1 , arr,dp);
            points+=coins(k+1 , j , arr,dp); 
            maxpoints = max(maxpoints , points);
        }
        return dp[i][j] = maxpoints;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return coins(1 , n-2 , nums , dp);
    }
};