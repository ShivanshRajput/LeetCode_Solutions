class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz , vector<int>(sz,0));
        for(int l=sz-2;l>=1;l--){
            for(int h=1;h<=sz-2;h++){
                if(l>h) continue;
                int mini = 1e8;
                for(int k=l;k<=h;k++){
                    int cost = (cuts[h+1] - cuts[l-1]) + dp[l][k-1] + dp[k+1][h];
                    mini = min(mini , cost);
                }
                dp[l][h] = (int)mini;
            }
        }
        return dp[1][sz-2];
    }
};