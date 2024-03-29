class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<int,int> freq;
        vector<int> ans;
        int minfreq = nums.size()/3 + 1;
        for(int &x:nums){
            freq[x]++;
            if(freq[x]==minfreq) ans.push_back(x);
        }
        return ans;
    }
};