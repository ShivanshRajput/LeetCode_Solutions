class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v , succProb[i]});
            adj[v].push_back({u , succProb[i]});
        }
        vector<double> prob(n , 0.0);
        priority_queue<pair<double,int>>  max_heap;
        prob[start] = 1.0;
        max_heap.push({prob[start], start});
        while(!max_heap.empty()){
            double curr_prob = max_heap.top().first;
            int node = max_heap.top().second;
            cout<<node<<" "<<curr_prob<<endl;
            max_heap.pop();
            for(auto &it: adj[node]){
                int child = it.first;
                double child_prob = it.second;
                double new_prob = curr_prob * child_prob;
                if(new_prob > prob[child]){
                    prob[child] = new_prob;
                    max_heap.push({new_prob , child});
                }
            }
        }
        return prob[end];
    }
};