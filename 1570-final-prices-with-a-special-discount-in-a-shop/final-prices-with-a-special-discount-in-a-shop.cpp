class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices;
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && prices[stk.top()] >= prices[i]){
                result[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};