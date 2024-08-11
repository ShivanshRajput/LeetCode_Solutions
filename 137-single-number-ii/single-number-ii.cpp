class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;  // stores xor of all numbers appearing once.. aka our required number
        int twos = 0;  // stores xor of all numbers appearing twice, we dont need threes
        for(int &x:nums){
            ones = (ones^x)&(~twos);   // if the no is not appeared twice, its first occurance
            twos = (twos^x)&(~ones);   // in second occurance of x, it got deleted from ones, so now if it is not in ones its added in twos
        }
        return ones;
    }
};