class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1 , 0);
        for(int i=n-1;i>=0;i--){
            int maxyet = arr[i];
            int maxsum = INT_MIN;
            for(int j=i;j<i+k && j<n;j++){
                maxyet = max(maxyet , arr[j]);
                int currsum = maxyet * (j-i+1) + dp[j+1];
                maxsum = max(maxsum , currsum);
            }
            dp[i] = maxsum;
        }
        return dp[0];
    }
};