class Solution {
public:
    bool check(int i , int j , string &s , string &p , vector<vector<int>> &dp){
        if(i>=s.size() and j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool match = i<s.size() and (s[i]==p[j] or p[j]=='.');
        if((j<p.size()-1) and p[j+1]=='*'){
            return dp[i][j] = check(i , j+2 , s , p ,dp) or (match and check(i+1 , j , s , p, dp));
        }
        if(match) return dp[i][j] = check(i+1 , j+1 , s , p ,dp);
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return check(0 , 0 , s , p ,dp);
    }
};