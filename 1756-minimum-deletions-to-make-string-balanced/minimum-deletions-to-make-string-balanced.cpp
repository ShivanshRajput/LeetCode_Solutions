class Solution {
public:
    int minimumDeletions(string s) {
        int n =  s.size();
        vector<int> preB(n) , sufA(n);
        preB[0] = (s[0] == 'b');
        sufA[0] = count(s.begin() , s.end() , 'a');
        for(int i=1;i<n;i++){
            preB[i]=preB[i-1] + (s[i]=='b');
            sufA[i]=sufA[i-1] - (s[i-1]=='a');
        }
        int count = n;
        for(int i=0;i<n;i++){
            count = min(count ,sufA[i] + preB[i] - 1 );
        }
        return count;
    }
};