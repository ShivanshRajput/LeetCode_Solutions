class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        long long mod = 1e9 + 7 ;
        vector<pair<int,int>>adj[n];
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            for(auto &it:adj[node]){
                long long adj_node = it.first;
                long long adj_wt = it.second;
                
                if(wt + adj_wt < dist[adj_node]){
                    pq.push({wt + adj_wt , adj_node});
                    dist[adj_node] = wt + adj_wt;
                    ways[adj_node] = ways[node];
                }
                else if(wt + adj_wt == dist[adj_node]){
                    ways[adj_node] = (ways[adj_node] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};