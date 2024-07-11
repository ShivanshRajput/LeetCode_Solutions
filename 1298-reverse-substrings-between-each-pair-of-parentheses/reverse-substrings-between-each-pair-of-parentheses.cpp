class Solution {
int i=0;
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        string ans;
        while(i<s.size()){
            if(s[i]==')'){
                i++;
                reverse(ans.begin() , ans.end());
                return ans;
            }
            else if(s[i]=='('){
                i++;
                ans += reverseParentheses(s);
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};