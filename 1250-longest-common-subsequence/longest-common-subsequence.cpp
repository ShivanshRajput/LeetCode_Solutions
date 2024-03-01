class Solution {
public:
    int lcs(int i,int j, string &s , string &t ,vector<vector<int>> &dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = 1 + lcs(i-1,j-1 ,s,t,dp);
        }
        return dp[i][j] = max(lcs(i-1, j,s,t,dp) , lcs(i,j-1,s,t,dp));
    }

    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return lcs(n-1 , m-1 , s,t,dp);
    }
};