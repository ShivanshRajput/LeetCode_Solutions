class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin() , dictionary.end());
        string word = "" , ans = "";
        bool found = 0;
        for(char c:sentence){
            if(c!=' '){
                word+=c;
                if(found == 0 && st.find(word)!=st.end()){
                    ans+=word;
                    found = 1;
                }
            }
            else{
                if(found == 0){
                    ans+=word;
                }
                word = "";
                ans+=" ";
                found = 0;
            }
        }
        if(found == 0){
            ans+=word;
        }
        return ans;
    }
};