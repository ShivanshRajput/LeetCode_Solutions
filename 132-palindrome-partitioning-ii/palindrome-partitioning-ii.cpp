class Solution {
public:
    bool ispal(int low , int high , string &s){
        while(low<high){
            if(s[low]==s[high]){
                low++; high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1 , 0);
        int j = n-1;
        for(int i=j;i>=0;i--){
            int mini = 1e7;
            for(int k=i;k<=j;k++){
                if(ispal(i,k,s)){
                    int curr = 1 + dp[k+1];
                    mini = min(mini , curr);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};