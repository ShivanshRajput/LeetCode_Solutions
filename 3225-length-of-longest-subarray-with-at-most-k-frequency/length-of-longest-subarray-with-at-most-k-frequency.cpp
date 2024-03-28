class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = nums.size();
        unordered_map<int,int> freq;
        int i=0;
        int len=0;
        for(int j=0;j<n;j++){
            freq[nums[j]]++;
            while(freq[nums[j]]>k and i<=j){
                freq[nums[i]]--;
                i++;
            }
            len = max(len , j-i+1);
        }
        return len;
    }
};