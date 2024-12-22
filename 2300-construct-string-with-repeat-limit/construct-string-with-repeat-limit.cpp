class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        sort(s.rbegin() , s.rend());
        string res;
        int freq = 1 , ptr = 0;
        for(int i=0;i<n;i++){
            if(!res.empty() && res.back()==s[i]){
                if(freq < repeatLimit){
                    res += s[i];
                    freq ++;
                }
                else{
                    ptr = max(ptr,i+1);
                    while(ptr<n && s[ptr]==s[i]) ptr++;
                    if(ptr<n){
                        res += s[ptr];
                        swap(s[i] , s[ptr]);
                        freq = 1;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                res+=s[i];
                freq = 1;
            }
        }
        return res;
    }
};