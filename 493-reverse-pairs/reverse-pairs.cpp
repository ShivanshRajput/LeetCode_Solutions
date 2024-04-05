class Solution {
public:
    
    void merge(vector<int>& arr, int low, int mid, int high){
        int cnt=0;
        int i =low, j=mid+1;
        vector<int> temp(high-low+1);
        int k=0;
        while(i<=mid and j<=high){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=high){
            temp[k++] = arr[j++];
        }
        for(int i=0;i<high-low+1;i++){
            arr[low + i] = temp[i];
        }
    }

    int countpairs(vector<int>& arr, int low, int mid, int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high and arr[i]>2*(long long)arr[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high){
        int cnt=0;
        if(low<high){
            int mid = (low+high)/2;
            cnt+=mergeSort(arr , low,mid);
            cnt+=mergeSort(arr , mid+1,high);
            cnt+=countpairs(arr,low,mid,high);
            merge(arr , low , mid , high);  // yaha pe array distort ho jaegi
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        return mergeSort(nums , 0 , nums.size()-1);
    }
};