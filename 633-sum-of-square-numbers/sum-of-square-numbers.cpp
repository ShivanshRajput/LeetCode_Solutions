class Solution {
public:
    bool isPerfectSquare(long long n){
        if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
            return true;
        }
        return false;
    }

    bool judgeSquareSum(int c) {
        if(c==0) return true;
        for(long long i=1;i*i<=c;i++){
            long long j = c - i*i;
            if(isPerfectSquare(j)) return true;
        }
        return false;
    }
};