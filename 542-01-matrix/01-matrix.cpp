class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<vector<int>> ans (mat.size(),vector<int>(mat[0].size() , -1));
        vector<vector<bool>> visited (mat.size(),vector<bool>(mat[0].size() , false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            ans[i][j]=dist;
            if(i>0 && !visited[i-1][j]){
                q.push({{i-1,j},dist+1});
                visited[i-1][j] = true;
            }
            if(i<mat.size()-1 && !visited[i+1][j]){
                q.push({{i+1,j},dist+1});
                visited[i+1][j] = true;
            }
            if(j>0 && !visited[i][j-1]){
                q.push({{i,j-1},dist+1});
                visited[i][j-1] = true;
            }
            if(j<mat[0].size()-1 && !visited[i][j+1]){
                q.push({{i,j+1},dist+1});
                visited[i][j+1] = true;
            }
            q.pop();
            
        }
        return ans;
    }
};