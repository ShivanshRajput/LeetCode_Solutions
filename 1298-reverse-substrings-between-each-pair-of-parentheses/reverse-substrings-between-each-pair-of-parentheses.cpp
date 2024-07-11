class Solution {
int i=0;
public:
    string reverseParentheses(string s) {
        string ans;
        while(i<s.size()){
            if(s[i]==')'){
                i++;
                reverse(ans.begin() , ans.end());
                // cout<<ans<<endl;
                return ans;
            }
            else if(s[i]=='('){
                i++;
                ans += reverseParentheses(s);
                // cout<<ans<<endl;
            }
            else{
                ans += s[i];
                i++;
                // cout<<ans<<endl;
            }
        }
        return ans;
    }
};