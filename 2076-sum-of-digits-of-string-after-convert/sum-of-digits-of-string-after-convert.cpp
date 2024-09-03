class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c: s){
            string num = to_string(int(c - 'a' +1));
            for(char c:num){
                sum+=(c-'0');
            }
        }
        s = to_string(sum);
        k--;
        while(k--){
            sum = 0;
            for(char c:s){
                sum+=(c-'0');
            }
            s = to_string(sum);
        }
        return stoi(s);
    }
};