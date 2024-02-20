class Solution {
public:
    // int pathsum(int i ,int j , vector<vector<int>>&mat , vector<vector<int>> &dp){
    //     int n=mat.size();
    //     if(i==n-1) return mat[n-1][j];
    //     if(j<0 or j>=n) return 1e5;
    //     if(dp[i][j]!=-1e5) return dp[i][j];
    //     int down = mat[i][j] + pathsum(i+1, j , mat,dp);
    //     int left=1e5 , right=1e5;
    //     if(j>0) left = mat[i][j] + pathsum(i+1, j-1 , mat,dp);
    //     if(j<n-1) right = mat[i][j] + pathsum(i+1, j+1 , mat,dp);
    //     return dp[i][j]= min({down , left , right});
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1e5));
    //     int minans=1e5;
    //     for(int j=0;j<n;j++){
    //         minans = min(minans , pathsum(0,j,matrix,dp));
    //     }
    //     return minans;
    // }
    
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down = matrix[i+1][j];
                int left= 1e6 , right= 1e6;
                if(j>0) left = matrix[i+1][j-1];
                if(j<n-1) right = matrix[i+1][j+1];
                matrix[i][j]+=min({down , left ,right});
            }
        }
        return *min_element(matrix[0].begin() , matrix[0].end());
    }
};