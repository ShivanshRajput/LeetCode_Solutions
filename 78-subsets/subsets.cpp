class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> list;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};