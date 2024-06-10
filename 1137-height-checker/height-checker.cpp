class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        vector<int>clone = heights;
        sort(clone.begin(),clone.end());
        uint_fast8_t cnt=0;
        for(uint_fast8_t i=0;i<clone.size();i++){
            cnt+=(clone[i]!=heights[i]);
        }
        return cnt;
    }
};