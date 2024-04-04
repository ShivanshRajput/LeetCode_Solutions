class Solution {
public:
    int maxDepth(string s) {
        int maxd=0;
        int depth=0;
        for(char c:s){
            if(c=='(') depth++;
            else if(c==')') depth--;
            maxd = max(maxd,depth);
        }
        return maxd;
    }
};