class Solution {
private:
    int firstOccurance(vector<int>& arr , int target){
        int n = arr.size();
        int low = 0, high = n-1;
        int first = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                first = mid;
                high = mid-1;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return first;
    }
    int lastOccurance(vector<int>& arr , int target){
        int n = arr.size();
        int low = 0, high = n-1;
        int last = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurance(nums,target) , lastOccurance(nums,target)};
    }
};