class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>after(2,vector<int>(k+1,0)) , curr(2,vector<int>(k+1,0)); 
        for(int idx=n-1;idx>=0;idx--){
            for(int limit=1;limit<k+1;limit++){ // buy =1
                curr[1][limit] = max(-prices[idx] + after[0][limit] , 0 + after[1][limit]);
            }
            for(int limit=1;limit<k+1;limit++){ // buy =0
                curr[0][limit] = max(prices[idx] + after[1][limit-1] ,0 + after[0][limit]);
            }
            after = curr;
        }
        return after[1][k];
    }
};