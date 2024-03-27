class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int maxsum=-1e6;
        int maxtillhere = -1e6;
        for(int &x:nums){
            maxtillhere = max(x , x+maxtillhere);
            maxsum = max(maxsum , maxtillhere);
        }
        return maxsum;
    }
};