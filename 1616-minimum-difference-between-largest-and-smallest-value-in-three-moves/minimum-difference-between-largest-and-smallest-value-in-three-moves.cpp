class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        int n = nums.size();
        sort(nums.begin() , nums.end());
        return min({abs(nums[0] - nums[n-4]) , abs(nums[1] - nums[n-3]) , abs(nums[2] - nums[n-2]) , abs(nums[3] - nums[n-1])});
    }
};