class Solution {
    private:
    int upperBound(vector<int> &arr, int x){
        int n = arr.size();
        int low = 0 , high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }	
        return ans;
    }
    int lowerBound(vector<int> &arr, int x){
        int n = arr.size();
        int low = 0 , high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]>=x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }	
        return ans;
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums , target);
        if(lb == n || nums[lb]!=target) return{-1,-1};
        int ub = upperBound(nums , target);
        return {lb , ub-1};
    }
};