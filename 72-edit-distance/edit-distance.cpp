class Solution {
public:
    short minDistance(string s, string t) {
        short n=s.size(),m=t.size();
        vector<short> prev(m+1 , 0) , curr(m+1,0);
        for(short j=1;j<=m;j++){
            prev[j]=j;
        }
        for(short i=1;i<=n;i++){
            curr[0] = i;
            for(short j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min({ prev[j] , curr[j-1] , prev[j-1] });
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};