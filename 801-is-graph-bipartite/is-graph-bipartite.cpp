class Solution {
private:
    bool dfs(int node , vector<vector<int>>&graph , vector<int>&visited){
        for(int &i:graph[node]){
            if(visited[i]==-1){
                visited[i] = (visited[node]+1)%2;
                if(dfs(i,graph,visited)==false) return false;
            }
            else if(visited[i]==visited[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(dfs(i,graph,visited)==false) return false;
            }
        }
        return true;
    }
};