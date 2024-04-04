class Solution {
public:
    int maxDepth(string s) {
        int maxd=0;
        int depth=0;
        for(char &c:s){
            if(c=='('){
                maxd = max(maxd,++depth);
            } 
            else if(c==')') depth--;
            else continue;
        }
        return maxd;
    }
};