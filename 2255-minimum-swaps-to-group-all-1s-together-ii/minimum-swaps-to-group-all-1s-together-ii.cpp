class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = accumulate(nums.begin() , nums.end() , 0);
        if(countOnes<=1) return 0;
        int zeros =countOnes - accumulate(nums.begin() , nums.begin()+countOnes , 0);
        int minSwaps = zeros;
        for(int i=0;i<n;i++){
            int j = (i+countOnes)%n;
            if(nums[i]<nums[j]){
                zeros--;
            }
            else if(nums[i]>nums[j]){
                zeros++;
            }
            minSwaps = min(minSwaps , zeros);
        }
        return minSwaps;
    }
};