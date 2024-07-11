class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n , vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0 , {0,0}});
        effort[0][0] = 0;
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second; 
            int eff = pq.top().first;
            if(r==n-1 && c==m-1) return eff;
            pq.pop();
            for(int k=0;k<4;k++){
                int i = r + dr[k];
                int j = c + dc[k];
                if(i>=0 && i<n && j>=0 && j<m){
                    int mxeff = max(effort[r][c] , abs(heights[i][j] - heights[r][c]));
                    if(mxeff<effort[i][j]){
                        effort[i][j] = mxeff;
                        pq.push({mxeff , {i,j}});
                    }
                }
            }
        }
        return 0;
    }
};