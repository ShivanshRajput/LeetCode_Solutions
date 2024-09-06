class Solution {
private:
    bool isDivisor(int x , vector<int>&nums , int threshold){
        int sum = 0;
        for(int & it: nums){
            sum += it/x + (it%x!=0);
        }
        return (sum<=threshold);
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low + high)/2;
            if(isDivisor(mid , nums , threshold)){
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