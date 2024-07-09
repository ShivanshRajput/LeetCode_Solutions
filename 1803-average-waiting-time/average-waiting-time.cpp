class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
        uint_fast64_t prev = 0;
        uint_fast64_t tot = 0;
        for(auto & it : customers){
            uint_fast64_t in = it[0];
            uint_fast64_t tm = it[1];
            if(prev>in){
                tm += prev - in;
            }
            tot += tm;
            prev = in + tm;
        }
        return ((double)tot)/customers.size();
    }
};