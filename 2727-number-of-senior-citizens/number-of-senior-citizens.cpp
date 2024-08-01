class Solution {
public:
    int countSeniors(vector<string>& details) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int seniors = 0;
        for(string & s: details){
            int age = (s[11]-'0')*10 + (s[12]-'0');
            seniors += (age>60);
        }
        return seniors;
    }
};