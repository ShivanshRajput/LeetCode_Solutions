class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        for(auto &i:intervals){
            if(ans.empty() or ans.back()[1] < i[0]){
                ans.push_back(i);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , i[1]);
            }
        }
        return ans;
    }
};