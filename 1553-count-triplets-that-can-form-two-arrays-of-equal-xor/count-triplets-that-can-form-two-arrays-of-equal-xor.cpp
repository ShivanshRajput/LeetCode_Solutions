class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int prexor[n+1];
        prexor[0] = 0;
        for(int i=0;i<n;i++){
            prexor[i+1] = prexor[i] ^ arr[i];
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prexor[i] == prexor[j+1]){
                    cnt+=j-i;
                }
            }
        }
        return cnt;
    }
};