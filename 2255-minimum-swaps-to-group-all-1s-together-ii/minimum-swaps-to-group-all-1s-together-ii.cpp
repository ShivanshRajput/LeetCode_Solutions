class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) countOnes++;
        }
        if(countOnes<=1) return 0;
        int zeros = 0;
        for(int j=0;j<countOnes;j++){
            if(nums[j]==0){
                zeros++;
            }
        }
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