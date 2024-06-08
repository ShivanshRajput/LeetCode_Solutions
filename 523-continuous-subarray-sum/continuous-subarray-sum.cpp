class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> rem;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            if(nums[i]%k==0 or rem.find(nums[i]%k)!=rem.end()){
                return true;
            }
            rem.insert(nums[i-1]%k);
        }
        return false;
    }
};