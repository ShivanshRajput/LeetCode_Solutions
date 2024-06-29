class Solution {
private:
    void dfs(int node ,int parent, vector<bool>&visited , vector<vector<int>>&adj , vector<vector<int>>&ancestor){
        visited[node] = true;
        for(int &i:adj[node]){
            if(!visited[i]){
                ancestor[i].push_back(parent);
                dfs(i,parent,visited,adj,ancestor);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<vector<int>> ancestor(n);
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(i,i,visited,adj,ancestor);
        }
        for(int i=0;i<n;i++){
            sort(ancestor[i].begin() , ancestor[i].end());
        }
        return ancestor;
    }
};