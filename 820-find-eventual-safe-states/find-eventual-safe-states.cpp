class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // usning kahn's algorithm
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(int &j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            for(int &i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            ans.push_back(node);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};