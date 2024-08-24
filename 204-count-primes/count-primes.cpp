class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        bool sieve[5000001] = {};
        for(int_fast32_t i=2;i*i<=n;i++){
            if(!sieve[i]){
                for(int_fast32_t j = i*i;j<=n;j+=i){
                    sieve[j] = true;
                }
            }
        }
        int count = 0;
        for(int_fast32_t i=2;i<n;i++){
            if(!sieve[i]) count++;
        }
        return count;
    }
};