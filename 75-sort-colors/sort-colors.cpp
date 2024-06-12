class Solution {
public:
    void sortColors(vector<int>& nums) { 
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int_fast8_t cnt0 = 0 , cnt1=0;
        for(int_fast8_t i=0;i<nums.size();++i){
            cnt0 += (nums[i]==0);
            cnt1 += (nums[i]==1);
        }
        for(int_fast8_t i=0;i<cnt0;++i) nums[i]=0;
        for(int_fast8_t i=cnt0;i<cnt0+cnt1;++i) nums[i]=1;
        for(int_fast8_t i=cnt0+cnt1;i<nums.size();++i) nums[i]=2;
    }
};