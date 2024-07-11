class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<pair<int_fast32_t,int_fast32_t>> adj[n];
        for(auto&it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int_fast32_t>cost(n,1e9);
        queue<pair<int_fast32_t,pair<int_fast32_t,int_fast32_t>>> q;
        q.push({0,{src,0}});
        cost[src] = 0;
        while(!q.empty()){
            int_fast32_t stops = q.front().first;
            int_fast32_t node = q.front().second.first;
            int_fast32_t cst = q.front().second.second;
            q.pop();
            if(stops<=k){
                for(auto&it:adj[node]){
                    int_fast32_t adj_node = it.first;
                    int_fast32_t price = it.second;
                    if(cost[adj_node] > cst + price){
                        cost[adj_node] = cst + price;
                        q.push({stops+1,{adj_node,cost[adj_node]}});
                    }
                }
            }
            else{
                break;
            } 
        }
        if(cost[dst]==1e9){
            return -1;
        }
        return cost[dst];
    }
};