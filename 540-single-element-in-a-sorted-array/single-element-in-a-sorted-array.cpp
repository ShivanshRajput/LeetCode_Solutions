class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = arr.size();
        if(n==1)
            return arr[0];
        int low = 0 , high = n-1;
        while(low<=high){
            int mid = (low + high)/2;
            if(mid == low) return arr[low];
            if(mid == high) return arr[high];
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            if(mid%2==0 && arr[mid]==arr[mid+1]){ // present in left
                low = mid+2;
            }
            else if(mid%2==1 && arr[mid]==arr[mid-1]){ // present in left
                low = mid+1;
            }
            else if(mid%2==0 && arr[mid]==arr[mid-1]){ //present in right
                high = mid-2;
            }
            else{  //present in right
                high = mid-1;
            }
        }
        return 0;
    }
};