class Solution {
public:
    int pathsum(int i ,int j , vector<vector<int>>&mat , vector<vector<int>> &dp){
        int n=mat.size();
        if(i==n-1) return mat[n-1][j];
        if(j<0 or j>=n) return 1e5;
        if(dp[i][j]!=-1e5) return dp[i][j];
        int down = mat[i][j] + pathsum(i+1, j , mat,dp);
        int left=1e5 , right=1e5;
        if(j>0) left = mat[i][j] + pathsum(i+1, j-1 , mat,dp);
        if(j<n-1) right = mat[i][j] + pathsum(i+1, j+1 , mat,dp);
        return dp[i][j]= min({down , left , right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e5));
        int minans=1e5;
        for(int j=0;j<n;j++){
            minans = min(minans , pathsum(0,j,matrix,dp));
        }
        return minans;
    }
};