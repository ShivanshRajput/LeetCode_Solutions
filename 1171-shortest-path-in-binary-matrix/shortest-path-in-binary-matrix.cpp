class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) {
            return -1;
        }
        if(n==1) return 1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        q.push({1,{0,0}});
        dist[0][0] = 1;
        int dr[8] = {-1,-1,-1,0,1,1,1,0};
        int dc[8] = {-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dis = q.front().first;
            for(int k=0;k<8;k++){
                int i = r + dr[k];
                int j = c + dc[k];
                if(i>=0 && i<n && j>=0 && j<n 
                && grid[i][j]==0 && dis + 1 < dist[i][j]){
                    if(i==n-1 && j==n-1){
                        return dis + 1;
                    }
                    dist[i][j] = dis + 1;
                    q.push({dis+1 , {i,j}});
                }
            }
            q.pop();
        }
        return -1;
    }
};