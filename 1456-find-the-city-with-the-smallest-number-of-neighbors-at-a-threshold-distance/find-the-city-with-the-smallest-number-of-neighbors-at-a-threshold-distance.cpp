class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        vector<vector<int>>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int mini = 1e9;
        int minCity = -1;
        for(int src = 0;src<n;src++){
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> min_heap;
            vector<int> distance(n,1e9);
            distance[src] = 0;
            min_heap.push({0,src});      
            while(!min_heap.empty()){
                int node = min_heap.top().second;
                int dist = min_heap.top().first;
                min_heap.pop();
                for(auto &it:adj[node]){
                    if(distance[it[0]] > distance[node] + it[1]){
                        distance[it[0]] = distance[node] + it[1];
                        min_heap.push({distance[it[0]] , it[0]});
                    }
                }
            }
            int cnt = 0;
            for(int &it:distance){
                if(it<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mini){
                mini = cnt;
                minCity = src;
            }
        }
        return minCity;
    }
};