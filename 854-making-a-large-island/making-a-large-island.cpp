class DisjointSet { 
public:
    vector<int> parent, size;
    DisjointSet(int n) { 
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
    bool isValid(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m ;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int ind=0;ind<4;ind++){
                        int adjx = i + dr[ind];
                        int adjy = j + dc[ind];
                        if(isValid(adjx,adjy,n,n) && grid[adjx][adjy]==1){
                            int nodeNo = i*n + j;
                            int adjNodeNo = adjx*n + adjy;
                            ds.unionBySize(nodeNo , adjNodeNo);
                        }
                    }
                }
            }
        }
        int maxSize = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> components;
                    for(int ind=0;ind<4;ind++){
                        int adjx = i + dr[ind];
                        int adjy = j + dc[ind];
                        if(isValid(adjx,adjy,n,n) && grid[adjx][adjy]==1){
                            int nodeNo = i*n + j;
                            int adjNodeNo = adjx*n + adjy;
                            components.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                    int totSize = 1;
                    for(auto &it:components){
                        totSize+=ds.size[it];
                    }
                    maxSize = max(maxSize , totSize);
                }
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxSize = max(maxSize, ds.size[ds.findUPar(cellNo)]);
        }
        return maxSize;
    }
};