class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rolled = rolls.size() + n;
        int sum = rolled * mean;
        int known = accumulate(rolls.begin() , rolls.end() , 0);
        sum -= known;
        if(sum < n || sum > 6*n){
            return {};
        }
        vector<int> ans(n , sum/n);
        sum%=n;
        for(int i=0;i<sum;i++){
            ans[i]++;
        }
        return ans;

    }
};