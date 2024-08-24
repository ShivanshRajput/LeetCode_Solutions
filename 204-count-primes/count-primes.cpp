class Solution {
public:
    int countPrimes(int n) {
        bool sieve[5000001] = {};
        for(int i=2;i*i<=n;i++){
            if(!sieve[i]){
                for(int j = i*i;j<=n;j+=i){
                    sieve[j] = true;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(!sieve[i]) count++;
        }
        return count;
    }
};