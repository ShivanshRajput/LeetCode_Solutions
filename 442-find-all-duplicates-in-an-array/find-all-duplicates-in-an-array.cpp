class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1] < 0 ){  // already appeared
                ans.push_back(abs(nums[i]));
            }
            else{  //   not appeared
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1] ;
            }
        }
        return ans;
    }
};