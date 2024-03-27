class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=nums.size();
        vector<int> ans(n);
        int pos_index=0 , neg_index=1;
        for(int&i:nums){
            if(i<0){
                ans[neg_index] = i;
                neg_index+=2;
            }
            else{
                ans[pos_index] = i;
                pos_index+=2;
            }
        }
        return ans;
    }
};