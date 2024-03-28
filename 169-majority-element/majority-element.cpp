class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = nums.front();
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