class Solution {
public:
    void dfs(int node , vector<vector<int>>& isConnected ,vector<bool> &visited){
        visited[node] = true;
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i] && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int cnt = 0;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                cnt++;
                dfs(i , isConnected , visited);
            }
        }
        return cnt;
    }
};