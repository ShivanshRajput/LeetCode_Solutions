class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto&it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>minTime(n+1,1e9);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        minTime[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto&it:adj[node]){
                int adj_node = it.first;
                int adj_time = it.second;
                if(time + adj_time < minTime[adj_node]){
                    minTime[adj_node] = time + adj_time;
                    pq.push({minTime[adj_node] , adj_node});
                }
            }
        }
        int timeToReachAll = *max_element(minTime.begin()+1 , minTime.end());
        if(timeToReachAll == 1e9){
            return -1;
        }
        return timeToReachAll;
    }
};