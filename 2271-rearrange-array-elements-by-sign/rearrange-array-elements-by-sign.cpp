class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
        int n=nums.size();
        vector<int> ans(n);
        int pos_index=0 , neg_index=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[neg_index] = nums[i];
                neg_index+=2;
            }
            else{
                ans[pos_index] = nums[i];
                pos_index+=2;
            }
        }
        return ans;
    }
};