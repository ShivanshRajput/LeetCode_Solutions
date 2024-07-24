class DisjointSet {
    vector<int> rank, parent, size; 
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
private:
    bool isValid(int i,int j,int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> heightOfWater(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                heightOfWater[grid[i][j]] = {i,j};
            }
        }
        vector<vector<bool>> visited (n,vector<bool>(n,false));
        DisjointSet ds(n*n);
        int dr[4] = {-1,0,1,0};
        int dc[4] = { 0,1,0,-1};
        for(int time=0;time<n*n;time++){
            int x = heightOfWater[time].first;
            int y = heightOfWater[time].second;
            visited[x][y] = true;
            for(int ind=0;ind<4;ind++){
                int adjx = x + dr[ind];
                int adjy = y + dc[ind];
                if(isValid(adjx, adjy , n , n) && visited[adjx][adjy]){
                    int nodeNo = x*n + y;
                    int adjNodeNo = adjx*n + adjy;
                    ds.unionByRank(nodeNo, adjNodeNo);
                }
            }
            if(ds.findUPar(0) == ds.findUPar(n*n-1)){
                return time;
            }
        }
        return n*n-1;
    }
};