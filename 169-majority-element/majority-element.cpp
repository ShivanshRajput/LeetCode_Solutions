class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int winner = nums[0];
        int votes=0;
        for(int&i:nums){
            if(i==winner){
                votes++;
            }
            else{
                votes--;
            }
            if(votes==0){
                winner = i;
                votes=1;
            }
        }
        return winner;
    }
};