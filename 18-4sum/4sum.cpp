class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1 , l=n-1;
                while(k<l){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum>(long long)target){
                        l--;
                    }
                    else if(sum<(long long)target){
                        k++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        k++;
                        while(k<l and nums[l]==nums[l+1]) l--;
                        while(k<l and nums[k]==nums[k-1]) k++;
                    }
                }
            }
        }
        return ans;
    }
};