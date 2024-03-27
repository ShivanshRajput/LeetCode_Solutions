class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
        int n = prices.size();
        int earn=0;
        int lowest = INT_MAX;
        for(int i=0;i<n;i++){
            lowest = min(lowest , prices[i]);    // finding abhii tak ka lowest kya hai 
            earn = max(earn , prices[i]-lowest);   // earn is maximum of abhi ki value minus abhi tak ka lowest
        }
        return earn;
    }
};