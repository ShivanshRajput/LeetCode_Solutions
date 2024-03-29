class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin() , nums.end());
        long long ans = 0;
        int l=0 , r=0 , n=nums.size();
        while(r<n){
            k-=(nums[r++]==maxi);
            while(k==0){
                k+=(nums[l++]==maxi);
            }
            ans+=l;
        }
        return ans;
    }
};