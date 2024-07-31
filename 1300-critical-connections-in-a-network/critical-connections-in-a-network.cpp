class Solution {
private:
    int timer = 0;
    void dfs(int src, int parent , vector<vector<int>>&adj , 
            vector<bool>& visited , vector<int>&time , 
            vector<int>&low , vector<vector<int>>& criticals){
        visited[src] = true;
        time[src] = low[src] = timer++;
        for(int &dst : adj[src]){
            if(dst == parent) continue;
            if(!visited[dst]){
                dfs(dst , src , adj , visited , time , low , criticals);
                low[src] = min(low[src] , low[dst]);
                if(low[dst] > time[src]){
                    criticals.push_back({src , dst});
                }
            }
            else{
                low[src] = min(low[src] , low[dst]);
            }
        }   
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> criticals;
        vector<bool> visited(n,false);
        vector<int> time(n,1e9) , low(n , 1e9);
        dfs(0 , -1 , adj , visited , time , low , criticals);
        return criticals;
    }
};