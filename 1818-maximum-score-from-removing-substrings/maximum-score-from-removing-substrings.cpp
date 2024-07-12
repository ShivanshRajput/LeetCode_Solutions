class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string top = "ab";
        string bot = "ba";
        int top_score = x;
        int bot_score = y;
        if(y>x){
            swap(top , bot);
            swap(top_score , bot_score);
        }
        int res = 0;
        vector<char>stk1;
        for(char &ch:s){
            if(!stk1.empty() && stk1.back()==top[0] && ch==top[1]){
                res += top_score;
                stk1.pop_back();
            }
            else{
                stk1.push_back(ch);
            }
        }
        vector<char>stk2;
        for(char ch:stk1){
            if(!stk2.empty() && stk2.back()==bot[0] && ch==bot[1]){
                res += bot_score;
                stk2.pop_back();
            }
            else{
                stk2.push_back(ch);
            }
        }
        return res;
    }
};