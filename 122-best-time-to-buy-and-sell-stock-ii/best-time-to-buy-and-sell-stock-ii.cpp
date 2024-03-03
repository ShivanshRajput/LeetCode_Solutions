class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int earn = 0;
        for(int i=0;i<n-1;i++){
            earn+=max(prices[i+1]-prices[i] , 0);
        }
        return earn;
    }
};