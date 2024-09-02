class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n-1;
        int mini = 5001;
        while(low<=high){
            int mid = (low+high)/2;
            mini = nums[mid];
            if(nums[mid] < nums[high]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return mini;
    }
};