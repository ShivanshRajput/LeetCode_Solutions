class Solution {
public:
    int minDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        uint_fast32_t n = nums.size();
        if(n<=4){
            return 0;
        }
        sort(nums.begin() , nums.end());
        return min({nums[n-4] - nums[0] ,
                    nums[n-3] - nums[1] , 
                    nums[n-2] - nums[2] , 
                    nums[n-1] - nums[3]});
    }
};