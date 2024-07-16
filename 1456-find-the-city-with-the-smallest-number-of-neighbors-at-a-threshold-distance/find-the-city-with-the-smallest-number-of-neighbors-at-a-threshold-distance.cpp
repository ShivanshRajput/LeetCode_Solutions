class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(auto &it:edges){
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++){
            mat[i][i] = 0;
        }
        vector<int> neighbours(n,0);
        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]!=1e9 && mat[via][j]!=1e9
                    && mat[i][via] + mat[via][j] < mat[i][j]){
                        mat[i][j] = mat[i][via] + mat[via][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    neighbours[i]++;
                }
            }
        }
        int minIndex = -1;
        int mini = 1e9;
        for(int i=0;i<n;i++){
            if(neighbours[i]<=mini){
                mini = neighbours[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
};