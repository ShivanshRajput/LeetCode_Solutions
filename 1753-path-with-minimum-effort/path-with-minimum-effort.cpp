class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
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
            pq.pop();
            // cout<<eff<<" "<<r<<" "<<c<<endl;
            for(int k=0;k<4;k++){
                int i = r + dr[k];
                int j = c + dc[k];
                if(i>=0 && i<n && j>=0 && j<m){
                    int mxeff = max(effort[r][c] , abs(heights[i][j] - heights[r][c]));
                    if(mxeff<effort[i][j]){
                        effort[i][j] = mxeff;
                        // cout<<mxeff<<" "<<i<<" "<<j<<endl;
                        pq.push({mxeff , {i,j}});
                    }
                }
            }
            
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<effort[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return effort[n-1][m-1];
    }
};