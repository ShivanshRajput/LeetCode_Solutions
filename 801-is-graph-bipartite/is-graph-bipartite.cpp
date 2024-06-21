class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                q.push(i);
                visited[i]=0;
                while(!q.empty()){
                    int node = q.front();
                    for(int & i : graph[node]){
                        if(visited[i]==-1){
                            q.push(i);
                            visited[i] = (visited[node]+1)%2;
                        }
                        else if(visited[i]==visited[node]) return false;
                    }
                    q.pop();
                }
            }
        }
        
        return true;
    }
};