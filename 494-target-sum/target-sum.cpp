class Solution {
public:
    int ways(int i , int tgt , vector<int> &nums ,vector<vector<int>> &dp){
        if(i==0){
            if(nums[0]==0 and tgt==0) return 2;
            if(tgt==0 or tgt==nums[0]) return 1;
            return 0;
        }
        if(dp[i][tgt] != -1) return dp[i][tgt] ; 
        int not_pick = ways(i-1 , tgt , nums ,dp);
        int pick = 0;
        if(nums[i] <= tgt){
            pick = ways(i-1 , tgt - nums[i] , nums ,dp);
        }
        return dp[i][tgt] = pick+not_pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n =nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        target = abs(target);
        sum-=target;
        if(sum<0) return 0;
        if(sum&1) return 0;
        target = sum/2;
        vector<vector<int>> dp(n , vector<int>(target+1 , -1));
        return ways(n-1 , target , nums , dp);
    }
};