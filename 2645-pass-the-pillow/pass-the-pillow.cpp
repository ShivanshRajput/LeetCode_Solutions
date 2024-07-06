class Solution {
public:
    int passThePillow(int n, int time) {
        n--;   // for 0 based indexing
        time = time%(2*n);
        if(time>=n){
            time = 2*n - time;
        }
        return time +1; // returning in 1 based indexing
    }
};

// 0 1 2 3
// 6 5 4 3
// 6 7 8 9 
