class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int_fast32_t j=0;
        for(int_fast32_t i=0;i<s.size() && j<t.size();i++){
            if(t[j]==s[i]){
                j++;
            }
        }
        return t.size() - j;
    }
};