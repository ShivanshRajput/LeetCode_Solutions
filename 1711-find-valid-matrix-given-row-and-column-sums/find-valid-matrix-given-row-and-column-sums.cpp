class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];
            }
        }
        return ans;
    }
};