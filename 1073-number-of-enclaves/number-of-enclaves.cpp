class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j] = 0;
        if(i>0 && grid[i-1][j]==1) dfs(i-1,j,grid);
        if(j>0 && grid[i][j-1]==1) dfs(i,j-1,grid);
        if(i<grid.size()-1 && grid[i+1][j]==1) dfs(i+1,j,grid);
        if(j<grid[0].size()-1 && grid[i][j+1]==1) dfs(i,j+1,grid);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[n-1][j]==1) dfs(n-1,j,grid);
        }
        for (int i=1;i<n-1;i++){
            if(grid[i][0]==1) dfs(i,0,grid);
            if(grid[i][m-1]==1) dfs(i,m-1,grid);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt += (grid[i][j] == 1);
            }
        }
        return cnt;
    }
};