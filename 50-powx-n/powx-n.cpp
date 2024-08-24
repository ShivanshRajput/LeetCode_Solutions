class Solution {
public:
    double myPow(double x, int n) {
        bool neg = (n<0);
        double ans = 1;
        n = abs(n);
        while(n>0){
            if(n&1){
                ans*=x;
                n--;
            }
            else{
                x*=x;
                n/=2;
            }
        }
        if(neg) return (1.0/ans);
        return ans;
    }
};