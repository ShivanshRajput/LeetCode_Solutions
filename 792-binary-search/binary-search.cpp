class Solution {
private:
    int binarySearch(vector<int>&nums , int target , int low , int high){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target){
            low = mid+1;
            return binarySearch(nums , target , low , high);
        }
        else{
            high = mid-1;
            return binarySearch(nums , target , low , high);
        }
        return 0;
    }
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int low = 0 , high = nums.size()-1;
        return binarySearch(nums , target , low , high);
    }
};