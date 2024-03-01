class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
        }
        string ans(n,'0');
        if(count==1){
            ans[n-1]='1';
        }
        else if(count>=2){
            ans[n-1]='1';
            count--;
            for(int i=0;i<count;i++){
                ans[i]='1';
            }
        }
        return ans;
    }
};