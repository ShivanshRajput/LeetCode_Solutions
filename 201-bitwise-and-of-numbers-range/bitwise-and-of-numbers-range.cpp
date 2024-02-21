class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        short count=0;
        while(left != right){
            count++;
            left>>=1;
            right>>=1;
        }
        return (left<<count);
    }
};