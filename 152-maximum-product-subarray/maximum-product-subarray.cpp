class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre=1,suf=1;
        int maxp = INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            pre*=nums[i];
            maxp = max(maxp , pre);
        }
        for(int i=n-1;i>=0;i--){
            if(suf==0) suf=1;
            suf*=nums[i];
            maxp = max(maxp , suf);
        }
        return maxp;
    }
};