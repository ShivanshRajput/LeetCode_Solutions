class Solution {
public:
    int minBitFlips(int start, int goal) {
        int differ = start^goal;
        return __popcount(differ);
    }
};