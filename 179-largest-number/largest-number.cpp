class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<string> ans;
        for(int &it: nums){
            ans.push_back(to_string(it));
        }
        auto cmp = [](string &x , string &y){
            return x+y > y+x;
        };
        sort(ans.begin() , ans.end() , cmp);
        string res = "";
        for(auto &it:ans){
            res += it;
        }
        if(res[0] == '0') return "0";
        return res;
    }
};