class Solution {
public:
    int maximumCherry(int r, int c, vector<vector<int>> &grid) {
        vector<vector<int>> front(c, vector<int>(c,-1));
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2){
                    front[j1][j2]=grid[r-1][j1];
                }
                else{
                    front[j1][j2]=grid[r-1][j1] + grid[r-1][j2];
                }
            }
        }
        for(int i=r-2;i>=0;i--){
            vector<vector<int>> curr (c, vector<int>(c,-1));
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxi=-1e6;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            if(j1+dj1>=0 and j1+dj1<=c-1 and j2+dj2>=0 and j2+dj2<=c-1){
                                if(j1==j2) maxi = max(maxi , grid[i][j1] + front[j1+dj1][j2+dj2]);
                                else  maxi=max(maxi ,grid[i][j1] + grid[i][j2] + front[j1+dj1][j2+dj2]);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][c-1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        return maximumCherry(r,c,grid);
    }
};