class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n);
        for(auto &it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree.begin() , degree.end());
        long long ans = 0;
        for (int i=0;i<n;i++) {
            ans += ((i+1)*degree[i]);
        }
        return ans;
    }
};