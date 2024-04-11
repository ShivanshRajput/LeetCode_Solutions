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

    int minpart(int i , int j , string &s , vector<int> &dp){
        if(i>j) return 0;
        if(dp[i]!= -1) return dp[i];
        int mini = 1e7;
        for(int k=i;k<=j;k++){
            if(ispal(i,k,s)){
                int curr = 1 + minpart(k+1, j,s , dp);
                mini = min(mini , curr);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return minpart(0 , n-1 , s , dp) - 1;
    }
};