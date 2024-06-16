class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int orange = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    orange++;
                }
                else if(grid[i][j]==1){
                    orange++;
                }
            }
        }
        int time =0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                int i = q.front().first;
                int j = q.front().second;
                if(i>0 && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                }   
                if(i<n-1 && grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j] = 2;
                } 
                if(j>0 && grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                }   
                if(j<m-1 && grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                }
                q.pop();
                orange--;
            }
            if(!q.empty()) time++;
        }
        if(orange == 0){
            return time;
        }
        return -1;
    }
};