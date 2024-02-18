class Solution {
public:
    int pickup(int i , int j1 , int j2 , int r , int c , vector<vector<int>>&grid , vector<vector<vector<int>>> &dp){
        if(j1<0 or j1>=c or j2<0 or j2>=c) return -1e6;
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e6;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2) maxi=max(maxi ,grid[i][j1] + pickup(i+1, j1+dj1,j2+dj2,r,c,grid ,dp));
                else maxi=max(maxi ,grid[i][j1] + grid[i][j2] + pickup(i+1, j1+dj1,j2+dj2,r,c,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r , vector<vector<int>>(c, vector<int>(c,-1)));
        return pickup(0 , 0 , c-1 , r , c , grid ,dp);
    }
};