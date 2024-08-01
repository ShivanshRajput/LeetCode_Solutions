class Solution {
public:
    int countSeniors(vector<string>& details) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int seniors = 0;
        for(string & s: details){
            int age = stoi(s.substr(11 , 2));
            if(age>60){
                seniors++;
            }
        }
        return seniors;
    }
};