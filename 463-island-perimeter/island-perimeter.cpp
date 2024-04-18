class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int peri=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(j!=0) peri+=grid[i][j-1]==0;
                    else peri++;
                    if(j!=m-1) peri+=grid[i][j+1]==0;
                    else peri++;
                    if(i!=0) peri+=grid[i-1][j]==0;
                    else peri++;
                    if(i!=n-1) peri+=grid[i+1][j]==0;
                    else peri++;
                }
            }
        }
        return peri;
    }
};