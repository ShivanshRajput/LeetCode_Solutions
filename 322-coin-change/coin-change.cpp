class Solution {
public:

    int coinChange(vector<int>& arr, int x) {
        int n=arr.size();
        vector<int>prev(x+1 , 0);
        for(int tgt =0;tgt<=x;tgt++){
            if(tgt%arr[0]==0) prev[tgt] = tgt/arr[0];
            else prev[tgt] = 1e9;
        }
        for(int idx=1;idx<n;idx++){
            vector<int>curr(x+1 , 0);
            for(int target=0;target<=x;target++){
                int not_pick= 0 + prev[target];
                int pick = 1e9;
                if(arr[idx]<=target) pick = 1 + curr[target-arr[idx]];
                curr[target] = min(pick , not_pick);
            }
            prev = curr;
        }
        int ans=prev[x];
        if(ans>=1e9) return -1;
        return ans;
    }
};