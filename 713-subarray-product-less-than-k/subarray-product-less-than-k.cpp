class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        int n = nums.size();
        if(k<=1) return 0;
        int left=0 , right=0 ;
        int product=1 , count = 0;
        while(right<n){
            product*=nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            count+= 1+right-left;  // counting subarrays ending upto 'right' in each step
            right++;
        }
        return count;
    }
};