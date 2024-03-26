class Solution {
public:
    bool check(string &s , string &t){
        if(s.size()+1 != t.size()) return false;
        int i=0 , j=0;
        while(j<t.size()){
            if(i<s.size() and s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==s.size() and j==t.size()) return true;
        return false;
    }

    static bool mycmp(string s1 , string s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = words.size();
        int maxi =0;
        vector<int>dp(n , 1);
        sort(words.begin() , words.end() , mycmp);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j], words[i]) and dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};