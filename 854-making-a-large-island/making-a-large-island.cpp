class DisjointSet { 
public:
    vector<int> parent, size;
    DisjointSet(int n) { 
        parent.resize(n);
        size.resize(n, 1); 
        iota(parent.begin(), parent.end(), 0);
    }

    int findUPar(int node) {
        if(node != parent[node])
            parent[node] = findUPar(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u != ulp_v) {
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }
    }
}; 

class Solution {
private:
    bool isValid(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        
        // Step 1: Create disjoint sets for existing islands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int ind = 0; ind < 4; ind++) {
                        int adjx = i + dr[ind];
                        int adjy = j + dc[ind];
                        if(isValid(adjx, adjy, n) && grid[adjx][adjy] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = adjx * n + adjy;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size by flipping one 0 to 1
        int maxSize = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> components;
                    int totSize = 1;  // Start with 1 as we are flipping this 0 to 1
                    for(int ind = 0; ind < 4; ind++) {
                        int adjx = i + dr[ind];
                        int adjy = j + dc[ind];
                        if(isValid(adjx, adjy, n) && grid[adjx][adjy] == 1) {
                            int adjNodeNo = adjx * n + adjy;
                            int root = ds.findUPar(adjNodeNo);
                            if(components.find(root) == components.end()) {
                                components.insert(root);
                                totSize += ds.size[root];
                            }
                        }
                    }
                    maxSize = max(maxSize, totSize);
                }
            }
        }

        // Step 3: Consider the case when no flip is needed (i.e., the entire grid is already 1s)
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            if (grid[cellNo / n][cellNo % n] == 1) {
                maxSize = max(maxSize, ds.size[ds.findUPar(cellNo)]);
            }
        }

        return maxSize;
    }
};
