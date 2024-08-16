class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = 1e6 , maxi = -1e6;
        int dist = 0;
        for(auto &it: arrays){
            dist = max(dist , maxi - it.front());
            dist = max(dist , it.back() - mini);
            mini = min(mini , it.front());
            maxi = max(maxi , it.back());
        }
        return dist;
    }
};