class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // calculation of adjacency matrix and indegrees for topological sort by kahn algirithm
        vector<vector<int>> adj(n);
        vector<int>indegree(n,0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        // identifying starting nodes
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // marking ancestors
        vector<set<int>> ancestors(n);
        while(!q.empty()){
            int node = q.front();
            for(int &i:adj[node]){
                ancestors[i].insert(node);
                for(int a: ancestors[node]){
                    ancestors[i].insert(a);
                }
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            q.pop();
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = vector<int>(ancestors[i].begin() , ancestors[i].end());
        }
        return ans;
    }
};