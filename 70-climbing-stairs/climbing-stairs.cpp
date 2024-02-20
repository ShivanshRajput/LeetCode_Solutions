class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int p2=0;
        int p1=1;
        for(int i=1;i<=n;i++){
            int cur=p1+p2;
            p2=p1;
            p1=cur;
        }
        return p1;
    }
};