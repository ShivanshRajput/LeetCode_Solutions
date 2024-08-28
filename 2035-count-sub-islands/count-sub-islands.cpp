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
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        DisjointSet ds(n*m);
        auto index = [&](int i, int j) { return i * m + j; };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    int current = index(i,j);
                    // down
                    if(i+1<n && grid2[i+1][j]){
                        ds.unionBySize(current , index(i+1,j));
                    }
                    // right
                    if(j+1<m && grid2[i][j+1]){
                        ds.unionBySize(current , index(i,j+1));
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==0){  // water underneath
                    ds.unionBySize(index(i,j) , n*m);
                }
            }
        }
        int islandCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    int root = ds.findUPar(index(i,j));
                    if(root != ds.findUPar(n*m)){   // checking if it is from the set of waterUnderneath
                        islandCount++;
                        ds.unionBySize(root , n*m);  // to avoid overcounting, added it to waterUnderneath group
                    }
                }
            }
        }
        return islandCount;
    }
    
};