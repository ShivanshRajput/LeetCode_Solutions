class Solution {
public:
    long long MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<int> arr;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin() , arr.end());
        int ans = 0;
        for(int i=left-1;i<=right-1;i++){
            ans = (ans + arr[i])%MOD;
        }
        return ans%MOD;
    }
    
};