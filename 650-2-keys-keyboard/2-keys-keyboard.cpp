class Solution {
private:
    int dp[1001] = {};
    int findFactor(int n){
        if (n==1) return -1;
        if (n==2 || n==3) return -1;
        if (n%2==0) return 2;
        if (n%3==0) return 3;
        for (int i=5;i*i<=n;i+=6){
            if (n%i==0){
                return i;
            }
            if (n%(i+2)==0){
                return i+2;
            }
        }
        return -1;
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        if(dp[n] != 0) return dp[n];
        int factor = findFactor(n);
        if(factor == -1){ // n is prime
            return n;
        }
        return dp[n] =  minSteps(factor) + minSteps(n/factor);
    }
};