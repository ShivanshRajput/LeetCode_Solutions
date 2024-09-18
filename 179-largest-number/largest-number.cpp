class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = nums.size();
        vector<string> arr(n);
        int i = 0;
        for(int &it: nums){
            arr[i++] = (to_string(it));
        }
        auto cmp = [](string &x , string &y){
            return x+y > y+x;
        };
        sort(arr.begin() , arr.end() , cmp);
        string res = "";
        for(auto &it:arr){
            res += it;
        }
        if(res[0] == '0') return "0";
        return res;
    }
};