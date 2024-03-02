class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.size() , m=t.size();
        vector<vector<int>> dp (n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        // here dp array has been created now were going to backtrack to obatin the desired string
        string ans="";
        int i=n,j=m;
        while(i>0 and j>0){
            if(s[i-1]==t[j-1]){
                ans = s[i-1] + ans;
                i--; j--;               // move diagonally up and left
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){  // move up
                    ans = s[i-1] + ans;
                    i--; 
                } 
                else{
                    ans = t[j-1] + ans;   // move left
                    j--;
                }                       
            } 	
        }
        while(i--){
            ans = s[i] + ans;

        }
        while(j--){
            ans = t[j] + ans;

        }
        return ans;
    }
};