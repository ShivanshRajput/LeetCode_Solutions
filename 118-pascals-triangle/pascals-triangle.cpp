class Solution {
public:
    vector<vector<int>> generate(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>>ans(n);
        ans[0] = {1};
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j>0 and j<i){
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
                else{
                    ans[i].push_back(1);
                }
            }
        }
        return ans;
    }
};