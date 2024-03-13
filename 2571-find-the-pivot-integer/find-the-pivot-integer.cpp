class Solution {
public:
    int pivotInteger(int n) {
        int z = n * (n+1) / 2 ;
        int p = sqrt(z);
        if(p*p == z) return p;
        return -1;
    }
};