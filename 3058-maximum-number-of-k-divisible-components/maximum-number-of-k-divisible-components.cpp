class Solution {
private:
    int dfs(int parentNode , int currNode , vector<vector<int>>&graph , vector<int>& values , int k , int &components){
        int subtreeSum = 0;
        for(auto & it : graph[currNode]){
            if(it!=parentNode){
                subtreeSum += dfs(currNode , it , graph , values , k , components);
                subtreeSum %= k;
            }
        }
        subtreeSum += values[currNode];
        subtreeSum %= k;
        if(subtreeSum==0) components++;
        return subtreeSum;
    } 
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for(auto & it : edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int components = 0;
        dfs(-1 , 0 , graph , values , k , components);
        return components;
    }
};