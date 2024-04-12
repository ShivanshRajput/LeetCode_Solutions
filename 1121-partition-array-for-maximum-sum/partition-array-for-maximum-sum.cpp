class Solution {
public:
    int solve(int i , int n , int  k , vector<int> &arr ,  vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!= -1) return dp[i];
        int maxyet = arr[i];
        int maxsum = INT_MIN;
        for(int j=i;j<i+k && j<n;j++){
            maxyet = max(maxyet , arr[j]);
            int currsum = maxyet * (j-i+1) + solve(j+1 , n , k ,arr ,dp);
            maxsum = max(maxsum , currsum);
        }
        return dp[i] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1 , -1);
        return solve(0 , n, k , arr ,dp);
    }
};