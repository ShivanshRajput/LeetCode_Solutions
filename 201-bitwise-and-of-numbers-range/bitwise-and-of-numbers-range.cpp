class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        if(left==0) return 0;
        if(__bit_width(left) != __bit_width(right)) return 0;
        int_fast8_t count=0;
        while(left != right){
            count++;
            left>>=1;
            right>>=1;
        }
        return (left<<count);
    }
};