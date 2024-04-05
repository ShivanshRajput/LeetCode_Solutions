class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(char i:s){
            if(!stk.empty() && abs(stk.top()-i)==32){
                stk.pop();
                continue;
            }
            stk.push(i);
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};