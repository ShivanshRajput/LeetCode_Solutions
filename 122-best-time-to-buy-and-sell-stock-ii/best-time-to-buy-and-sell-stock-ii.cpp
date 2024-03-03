class Solution {
public:
    int_fast32_t maxProfit(vector<int>& prices) {
        int_fast32_t earn = 0;
        for(short i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) earn+=prices[i]-prices[i-1];
        }
        return earn;
    }
};