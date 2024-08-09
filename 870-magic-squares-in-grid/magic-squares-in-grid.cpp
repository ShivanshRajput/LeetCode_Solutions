class Solution {
private:
    bool isMagic(int i,int j,vector<vector<int>>&grid){
        unordered_set<int>st;
        int sr[3] = {};
        int sc[3] = {};
        int d[2] = {};
        for(int r=i;r<i+3;r++){
            for(int c=j;c<j+3;c++){
                int node = grid[r][c];
                if (node < 1 || node > 9) return false; 
                st.insert(node);
                sr[r - i] += node;
                sc[c - j] += node;
                if (r - i == c - j) {
                    d[0] += node;
                }
                if (r - i + c - j == 2) {  
                    d[1] += node;
                }
            }
        }
        if(st.size()!=9) return false;
        return sr[0] == 15 && sr[1] == 15 && sr[2] == 15 &&
               sc[0] == 15 && sc[1] == 15 && sc[2] == 15 &&
               d[0] == 15 && d[1] == 15;
        
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                count += isMagic(i,j,grid);
            }
        }
        return count;
    }
};