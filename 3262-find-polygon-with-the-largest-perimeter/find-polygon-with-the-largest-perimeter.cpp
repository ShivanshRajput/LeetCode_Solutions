class Solution {
public:
    

    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin() , nums.end() , 0ll );

        for(long long i=nums.size()-1;i>=0;i--){
            sum-=nums[i];
            if(nums[i]<sum){
                sum+=nums[i];
                break;
            }
            if(i==0){
                sum=-1;
                break;
            }
        }
        return sum;
    }
};