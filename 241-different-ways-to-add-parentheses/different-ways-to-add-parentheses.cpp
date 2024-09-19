class Solution {
    unordered_map<string , vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string expression) {
        if(dp.find(expression) != dp.end()){
            return dp[expression];
        }
        int n = expression.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            char oper = expression[i];
            if(oper=='+' || oper=='-' || oper=='*'){
                vector<int> s1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i+1));
                for(int & a: s1){
                    for(int & b:s2){
                        if(oper == '+'){
                            ans.push_back(a+b);
                        }
                        else if(oper == '-'){
                            ans.push_back(a-b);
                        }
                        else {
                            ans.push_back(a*b);
                        }
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return dp[expression] = ans;
    }
};