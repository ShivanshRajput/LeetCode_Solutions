class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> prev(n+1 , 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1 , 0);
            for(int j=n;j>=1;j--){
                if(s[i-1]==s[j-1]) curr[j-1] = 1 + prev[j];
                else curr[j-1] = max(prev[j-1] , curr[j]);
            }
            prev = curr;
        }
        return prev[0];
    }
};