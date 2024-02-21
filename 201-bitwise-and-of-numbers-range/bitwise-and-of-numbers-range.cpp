class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(__bit_width(left) == __bit_width(right)){
            long ans = 2147483647;
            for(long i=left;i<=right and i<2147483647;i++){
                ans &=i;
            }
            return ans;
        }
        return 0;
    }
};