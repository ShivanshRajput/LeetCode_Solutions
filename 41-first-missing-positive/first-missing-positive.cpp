class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 and nums[i]<n and nums[i]!=nums[nums[i]]){
                swap(nums[i] , nums[nums[i]]);
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};