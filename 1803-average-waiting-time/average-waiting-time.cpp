class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
        uint_fast64_t n = customers.size();
        uint_fast64_t prev = 0;
        uint_fast64_t tot = 0;
        for(uint_fast64_t i=0;i<n;i++){
            uint_fast64_t in = customers[i][0];
            uint_fast64_t tm = customers[i][1];
            if(prev>in){
                tm += prev - in;
            }
            tot += tm;
            prev = in + tm;
        }
        return (1.0*tot)/n;
    }
};