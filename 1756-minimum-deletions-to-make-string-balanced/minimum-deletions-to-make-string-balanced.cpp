class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n =  s.size();
        int preB = (s[0] == 'b');
        int sufA = count(s.begin() , s.end() , 'a');
        int count = preB + sufA - 1;
        for(int i=1;i<n;i++){
            preB+=(s[i]=='b');
            sufA-=(s[i-1]=='a');
            count = min(count , preB + sufA - 1);
        }
        return count;
    }
};