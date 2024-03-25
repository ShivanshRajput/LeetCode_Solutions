class Solution {
public:
    bool check(int i , int j , string &s , string &p){
        if(i>=s.size() and j>=p.size()) return true;
        if(j>=p.size()) return false;
        bool match = i<s.size() and (s[i]==p[j] or p[j]=='.');
        if((j<p.size()-1) and p[j+1]=='*'){
            return check(i , j+2 , s , p) or (match and check(i+1 , j , s , p));
        }
        if(match) return check(i+1 , j+1 , s , p);
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return check(0 , 0 , s , p);
    }
};