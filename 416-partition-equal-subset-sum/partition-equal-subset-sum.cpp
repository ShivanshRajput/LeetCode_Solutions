class Solution {
public:
    bool solve(int i , int target , vector<int>& nums , vector<vector<int>>&dp){
        if(target == 0) return true;
        if(i==0) return target==nums[0];
        if(dp[i][target] != -1) return dp[i][target];
        bool notpick = solve(i-1 , target , nums,dp);
        bool pick = false;
        if(nums[i] <= target){
            pick = solve(i-1 , target - nums[i] , nums,dp);
        }
        return dp[i][target] = pick or notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum&1) return false;
        int target = sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1 , target , nums ,dp);
    }
};