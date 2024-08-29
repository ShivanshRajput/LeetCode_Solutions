class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int low = 0 , high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};