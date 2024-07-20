class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>ans(n , vector<int>(m,0));
        int i=0,j=0;
        while(i<n && j<m){
            if(rowSum[i] <= colSum[j]){
                ans[i][j] = rowSum[i];
                colSum[j]-= rowSum[i];
                rowSum[i]=0;
                i++;
            }
            else{
                ans[i][j] = colSum[j];
                rowSum[i]-= colSum[j];
                colSum[j]=0;
                j++;
            }
        }
        return ans;
    }
};