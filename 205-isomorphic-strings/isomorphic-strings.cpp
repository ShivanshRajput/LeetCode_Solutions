class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(200,0);
        vector<int> indexT(200,0);
        if(s.size()!=t.size()) return false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(indexS[s[i]] != indexT[t[i]]){
                return false;
            }
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};