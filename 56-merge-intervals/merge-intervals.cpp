class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() or ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        return ans;
    }
};