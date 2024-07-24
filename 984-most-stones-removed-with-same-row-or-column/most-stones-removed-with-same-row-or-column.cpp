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
    
    int noOfComponents(){
        int cnt = 0;
        for(int i=0;i<parent.size();i++){
            if(parent[i] == i && size[i]!=1) cnt++;
        }
        return cnt;
    }
}; 

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int noOfStones = stones.size();
        int rows = 0, cols = 0;
        for(auto &it : stones){
            rows = max(rows , it[0]);
            cols = max(cols , it[1]);
        }
        DisjointSet ds(rows+1 + cols+1);    // +1 would have worked as in disjointSet implementation we are taking n+1 size declarations;
        for(auto &it : stones){
            int xNo = it[0];
            int yNo = it[1] + rows + 1;
            ds.unionBySize(xNo , yNo);
        }
        return noOfStones - ds.noOfComponents(); // because of one last index being alone and always connected to itself in disjointSet it will increase the count of components in 0 based indexing. so a +1 in subtraced answer.
    }
};