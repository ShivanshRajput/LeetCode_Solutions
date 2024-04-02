class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1 , k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++; k--;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};