class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n ,1) , hash(n);
        int lastindex = 0;
        int maxi =1;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> ans(maxi);
        int idx =0 ;
        while(hash[lastindex] != lastindex){
            ans[idx++] = nums[lastindex];
            lastindex = hash[lastindex];
        }
        ans[idx] = nums[lastindex];
        reverse(ans.begin() , ans.end());
        return ans;
    }
};