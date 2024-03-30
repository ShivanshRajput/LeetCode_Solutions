class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0 , count=0;
        unordered_map<int,int>presum;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int rem = sum-k;
            if(presum.find(rem) != presum.end()){
                count+=presum[rem];
            }
            presum[sum]++;
        }
        return count;
    }
};