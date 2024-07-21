class Solution {
private:
    vector<int> findSequence(vector<vector<int>>& conditions , int k){
        vector<vector<int>> adj(k+1);
        vector<int>inDegree(k+1,0);
        for (auto& it : conditions) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (result.size() != k) {
            return {}; // if cycles present
        }
        return result;

    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowSequence = findSequence(rowConditions , k);
        vector<int> colSequence = findSequence(colConditions , k);
        if(rowSequence.empty() || colSequence.empty()){
            return {};
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rowSequence[i] == colSequence[j]){
                    ans[i][j] = rowSequence[i];
                }
            }
        }
        return ans;
    }
};