class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n=s.size();
        bool count = false;
        int len=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                count = true;
                len++;
            }
            else if(count){
                break;
            }
        }
        return len;
    }
};