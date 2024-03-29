class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = nums.size();
        vector<int> dp(n,1) , count(n,1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and 1+dp[j] > dp[i]){
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }
                else if(nums[i]>nums[j] and 1+dp[j] == dp[i]){
                    count[i] += count[j];
                }
            }
            maxi=max(maxi , dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans += count[i];
            }
        }
        return ans;
    }
};