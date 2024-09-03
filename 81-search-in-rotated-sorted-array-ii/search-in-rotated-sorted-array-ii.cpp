class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[mid] <= nums[high]){ // right is sorted
                if(target <= nums[high] && target >= nums[mid]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
            else{                        // left is sorted
                if(target <= nums[mid] && target >= nums[low]){
                    high = mid -1;
                }
                else{
                    low = mid  +1;
                }
            }
        }
        return false;
    }
};