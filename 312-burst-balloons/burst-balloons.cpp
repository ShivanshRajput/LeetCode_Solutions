class Solution {
public:
    int maxCoins(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxpoints = INT_MIN;
                for(int k=i;k<=j;k++){ // we are following to burst from last .. watch strivers video
                    int points=nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxpoints = max(maxpoints , points);
                }
                dp[i][j] = maxpoints;
            }
        }
        return dp[1][n-2];
    }
};