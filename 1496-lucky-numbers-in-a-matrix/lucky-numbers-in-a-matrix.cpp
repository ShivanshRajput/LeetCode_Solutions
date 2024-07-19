class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> maxCol(m,0);
        vector<int> minRow(n,1e6);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minRow[i] = min(minRow[i] , matrix[i][j]);
                maxCol[j] = max(maxCol[j] , matrix[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};