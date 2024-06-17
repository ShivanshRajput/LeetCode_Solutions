class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int_fast64_t i=1 , j=sqrt(c);
        if(j*j == c) return true;
        while(i<=j){
            int_fast64_t sum = i*i + j*j ;
            if(sum == c) return true;
            else if(sum < c) i++;
            else j--;
        }
        return false;
    }
};