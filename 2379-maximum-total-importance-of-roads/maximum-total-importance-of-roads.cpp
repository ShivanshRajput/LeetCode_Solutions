class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        long long degree[50000]={};
        for(auto &it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree, degree+n);
        long long ans = 0;
        for (int i=0;i<n;i++) {
            ans += ((i+1)*degree[i]);
        }
        return ans;
    }
};