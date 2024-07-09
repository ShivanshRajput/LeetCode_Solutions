class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long prev = 0;
        long long tot = 0;
        for(auto & it : customers){
            long long in = it[0];
            long long tm = it[1];
            if(prev>in){
                tm += prev - in;
            }
            tot += tm;
            prev = in + tm;
        }
        return ((double)tot)/customers.size();
    }
};