class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> dp(1);         // declare bitset of size 10001 named 'dp' with decimal value equivalent to 1 (i.e. lsb = 1)
        int sum=0;
        for(int &x:nums){
            sum+=x;
            dp = dp | (dp<<x);        // exactly similar to not_pick or pick 'x' in nums
        }
        if(sum&1) return false;       // if sum is odd, partition cant be made.
        return dp[sum/2];              // if sum is even, target is to reach half of total sum.
    }
};