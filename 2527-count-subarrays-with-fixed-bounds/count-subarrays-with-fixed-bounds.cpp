class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int left=-1, right=-1, bad=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK or nums[i]>maxK) bad = i;
            if(nums[i]==minK) left=i;
            if(nums[i]==maxK) right=i;
            count+= max(0, min(left,right) - bad);
        }
        return count;
    }
};