class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustHai(n+1);
        vector<int> trustKarta(n+1);
        for(auto &x:trust){
            trustKarta[x[0]]++;
            trustHai[x[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(trustHai[i] == n-1 and trustKarta[i] == 0) return i;
        }
        return -1;
    }
};