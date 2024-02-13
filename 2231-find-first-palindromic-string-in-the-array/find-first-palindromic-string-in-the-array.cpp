class Solution {
public:
    bool ispal(string &s){
        return equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) ;
    }

    string firstPalindrome(vector<string>& words) {
        for(string &x : words){
            if(ispal(x)){
                return x;
            }
        }
        return "";
    }
};