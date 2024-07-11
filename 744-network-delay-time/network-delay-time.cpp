class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<pair<int,int>> adj[n+1];
        for(auto&it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,int>> st;
        vector<int> distance(n+1,1e8);
        distance[k] = 0;
        st.insert({0,k});
        while(!st.empty()){
            int curr_node = st.begin()->second;
            int curr_dist = st.begin()->first;
            st.erase(st.begin());
            for(auto &it:adj[curr_node]){
                int adj_node = it.first;
                int adj_wt = it.second;
                int alter_dist = curr_dist + adj_wt;
                if(alter_dist < distance[adj_node]){
                    if(distance[adj_node] != 1e8){ // erasing previous lenthier way to this adj_node
                        st.erase({distance[adj_node] , adj_node});
                    }
                    distance[adj_node] = alter_dist;
                    st.insert({distance[adj_node] , adj_node});
                }
            }
        }
        int timeToReachAll = *max_element(distance.begin()+1 , distance.end());
        if(timeToReachAll == 1e8){
            return -1;
        }
        return timeToReachAll;
    }
};