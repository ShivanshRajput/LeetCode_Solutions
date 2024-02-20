class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prevRow(m,-1);
        for(int i=0;i<n;i++){
            vector<int>currRow(m,-1);
            for(int j=0;j<m;j++){
                if(i==0 and j==0) currRow[j] = grid[i][j];
                else{
                    int down=1e8, right=1e8;
                    if(i>0) down=grid[i][j] + prevRow[j];
                    if(j>0) right=grid[i][j] + currRow[j-1];
                    currRow[j]=min(down,right);
                }
            }
            prevRow = currRow;
        }
        return prevRow[m-1];
    }
};