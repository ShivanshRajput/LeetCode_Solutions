class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int>numbers;
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tgt = -(nums[i]+nums[j]);
                if(numbers.find(tgt)!=numbers.end()){
                    vector<int>temp={nums[i] , nums[j] , tgt};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
            numbers.insert(nums[i]);
        }
        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
};