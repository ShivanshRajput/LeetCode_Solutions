class Solution {
public:
    int move(int idx , vector<int>&arr , vector<int>&dp){
        if(idx>=arr.size()-1){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int mini = 1e8;
        for(int i=1;i<=arr[idx];i++){
            mini = min(mini ,1 + move(idx+i , arr , dp));
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()-1 , -1);
        return move(0 , nums , dp);
    }
};