class Solution {
public:
    bool check(int i, int j, string &s , string &t , vector<vector<short>> &dp){
        if(i<0){
            if(j<0) return true;
            else return false;
        }
        if(j<0){
            for(int x=0;x<=i;x++){
                if(s[x]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j] or s[i]=='?'){
            return dp[i][j] = check(i-1,j-1,s,t,dp);
        }
        if(s[i]=='*'){
            return dp[i][j] = check(i,j-1,s,t,dp) or check(i-1,j,s,t,dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string t, string s) {
        int n=s.size();
        int m=t.size();
        vector<vector<short>> dp(n,vector<short>(m,-1));
        return check(n-1,m-1,s,t,dp);
    }
};