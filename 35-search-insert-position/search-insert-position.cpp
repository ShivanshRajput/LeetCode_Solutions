class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(); // implement simple lower bound
        int low = 0 , high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }	
        return ans;
    }
};