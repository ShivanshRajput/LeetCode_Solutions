class Solution {
public:
    int nthUglyNumber(int n) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int indA = 0 , indB = 0 , indC = 0;
        int uglyNo[n];
        uglyNo[0] = 1;
        for(int i=1;i<n;i++){
            int newA = uglyNo[indA] * 2;
            int newB = uglyNo[indB] * 3;
            int newC = uglyNo[indC] * 5;
            int mini = min({newA , newB , newC});
            if(mini == newA) indA++;
            if(mini == newB) indB++;
            if(mini == newC) indC++;
            uglyNo[i] = mini;
        }
        return uglyNo[n-1];
    }
};