class Solution {
public:
    int steps(short i,short j, string &s, string &t , vector<vector<short>> &dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = steps(i-1, j-1, s, t,dp);
        }
        else{
            return dp[i][j] = 1 + min({steps(i-1,j,s,t,dp) , steps(i,j-1,s,t,dp) , steps(i-1,j-1,s,t,dp)});
        } 
    }

    int minDistance(string word1, string word2) {
        short n=word1.size(),m=word2.size();
        vector<vector<short>> dp(n,vector<short>(m,-1));
        return steps(n-1, m-1, word1, word2 ,dp);
    }
};