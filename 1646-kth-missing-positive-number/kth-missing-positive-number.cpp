class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = arr.size();
        int low = 0 , high = n-1;
        while(low<=high){
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high + k + 1; // this formula is derived.. see video
    }
};