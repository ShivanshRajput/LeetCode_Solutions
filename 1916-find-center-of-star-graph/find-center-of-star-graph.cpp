class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if(e[0][0]==e[1][0] || e[0][0]==e[1][1]) return e[0][0];
        return e[0][1];
    }
};