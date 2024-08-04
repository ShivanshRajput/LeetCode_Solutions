class Solution {
public:
    long long MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        vector<int>presum(n+1,0);
        presum[0] = 0;
        for(int i=0;i<n;i++){
            presum[i+1] = presum[i] + nums[i];
        }
        vector<int> arr;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum = presum[j] - presum[i];
                arr.push_back(sum);
            }
        }
        sort(arr.begin() , arr.end());
        int ans = 0;
        for(int i=left-1;i<=right-1;i++){
            ans = (ans + arr[i])%MOD;
        }
        return ans;
    }
    
};