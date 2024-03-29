class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if(nums.size()==0) return 0;
        sort(nums.begin() , nums.end());
        int count = 1 , maxcount = 1;
        int lastsmaller = nums.front();
        for(int &x:nums){
            if(x - lastsmaller==1){
                lastsmaller = x;
                count++;
                maxcount = max(maxcount , count);
            }
            else if(x != lastsmaller){
                count=1;
                lastsmaller = x;
            }
        }
        return maxcount;
    }
};