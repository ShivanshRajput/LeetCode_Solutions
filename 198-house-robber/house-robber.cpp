class Solution {
public:
    int maxNonAdj(int idx , vector<int> &nums , vector<int> &dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx] + maxNonAdj(idx-2 , nums,dp);
        int nopick =  0 + maxNonAdj(idx-1 , nums,dp);
        return dp[idx] = max(pick , nopick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n ,-1);
        return maxNonAdj(n-1 , nums ,dp);
    }
};