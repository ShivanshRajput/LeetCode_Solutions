class Solution {
    bool possible(int partSum , vector<int>&nums , int parts){
        int curSum = 0;
        int partCnt = 1;
        for(int &it:nums){
            if(curSum + it <= partSum){
                curSum += it;
            }
            else{
                partCnt++;
                curSum = it;
            }
            if(partCnt > parts) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(mid,nums,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};