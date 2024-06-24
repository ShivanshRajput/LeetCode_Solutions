class Solution {
public:
    bool dfs(int node , vector<vector<int>>& graph , vector<bool>&safe , vector<bool>&path , vector<bool>&visited){
        visited[node] = true;
        path[node] = true;
        safe[node] = true;
        for(int & it:graph[node]){
            if(!visited[it]){
                if(dfs(it,graph,safe,path,visited)==false){
                    safe[node] = false;
                    return false;
                }
            }
            else if(path[it]){
                safe[node] = false;
                return false;
            }
            
        }
        path[node] = false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>safe(n,false);
        vector<bool>path(n,false);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,safe,path,visited);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};