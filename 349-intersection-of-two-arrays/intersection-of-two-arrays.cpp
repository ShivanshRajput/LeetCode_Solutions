class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int>ans;
        for(auto &x: set2){
            if(set1.find(x) != set1.end()){
                ans.push_back(x);
            }
        }
        return ans;
    }
};