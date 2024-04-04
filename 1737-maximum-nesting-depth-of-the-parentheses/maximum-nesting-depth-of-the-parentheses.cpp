class Solution {
public:
    int maxDepth(string s) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int maxd=0;
        int depth=0;
        for(char &c:s){
            if(c=='('){
                depth++;
                maxd = max(maxd,depth);
            } 
            else if(c==')') depth--;
            else continue;
        }
        return maxd;
    }
};