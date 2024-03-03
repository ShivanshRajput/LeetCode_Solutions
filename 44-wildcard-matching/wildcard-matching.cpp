class Solution {
public:
    bool isMatch(string t, string s) {
        int n=s.size();
        int m=t.size();
        bool dp[2001][2001]={};
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]!='*'){
                break;
            }
            else{
                dp[i][0]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1] or s[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1]=='*'){
                    dp[i][j] = dp[i][j-1] or dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};