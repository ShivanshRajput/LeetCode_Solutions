class Solution {
private:
    bool isValid(int i,int j,int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n , vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        time[0][0] = grid[0][0];
        int dr[4] = {-1,0,1,0};
        int dc[4] = { 0,1,0,-1};
        while(!pq.empty()){
            int curr_time = pq.top().first;
            int curr_row = pq.top().second.first;
            int curr_col = pq.top().second.second;
            pq.pop();
            if(curr_row==n-1 && curr_col==m-1) return curr_time;
            for(int ind=0;ind<4;ind++){
                int adj_row = curr_row + dr[ind];
                int adj_col = curr_col + dc[ind];
                if(isValid(adj_row,adj_col,n,m)){
                    int alter_time = max(time[curr_row][curr_col] , grid[adj_row][adj_col]);
                    if(alter_time < time[adj_row][adj_col]){
                        time[adj_row][adj_col] = alter_time;
                        pq.push({alter_time , {adj_row,adj_col}});
                    }
                }
            }
        }
        return 0;
    }
};