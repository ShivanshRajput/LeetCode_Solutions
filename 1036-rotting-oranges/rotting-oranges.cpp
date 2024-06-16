class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int time = 0;
        int orange = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},time});
                    visited[i][j] = true;
                    orange++;
                }
                else if(grid[i][j]==1){
                    orange++;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            if(i>0 and grid[i-1][j]==1 and !visited[i-1][j]){
                q.push({{i-1,j},t+1});
                visited[i-1][j] = true;
            }   
            if(i<n-1 and grid[i+1][j]==1 and !visited[i+1][j]){
                q.push({{i+1,j},t+1});
                visited[i+1][j] = true;
            } 
            if(j>0 and grid[i][j-1]==1 and !visited[i][j-1]){
                q.push({{i,j-1},t+1});
                visited[i][j-1] = true;
            }   
            if(j<m-1 and grid[i][j+1]==1 and !visited[i][j+1]){
                q.push({{i,j+1},t+1});
                visited[i][j+1] = true;
            }
            time = t;
            q.pop();
            orange--;
        }
        if(orange == 0){
            return time;
        }
        return -1;
    }
};