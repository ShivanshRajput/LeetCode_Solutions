class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>great(2,0) , next(2,0) , curr(2,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    curr[buy] = max(-prices[idx] + next[0] , next[1]);
                }
                else{
                    curr[buy] = max(prices[idx] + great[1] ,  next[0]);
                }
            }
            great = next;
            next = curr;
        }
        return next[1];
    }
};