class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        int ptr = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i] , nums[ptr]);
                ptr++;
            }
        }
        return;
    }
};