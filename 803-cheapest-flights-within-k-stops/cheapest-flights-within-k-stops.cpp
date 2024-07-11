class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<pair<int,int>> adj[n];
        for(auto&it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>cost(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        cost[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cst = q.front().second.second;
            q.pop();
            if(stops<=k){
                for(auto&it:adj[node]){
                    int adj_node = it.first;
                    int price = it.second;
                    if(cost[adj_node] > cst + price){
                        cost[adj_node] = cst + price;
                        q.push({stops+1,{adj_node,cost[adj_node]}});
                    }
                }
            }   
        }
        if(cost[dst]==1e9){
            return -1;
        }
        return cost[dst];
    }
};