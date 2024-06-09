class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>rem;
        int count = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if((sum%k + k)%k==0) count++;
            if(rem.find((sum%k + k)%k)!=rem.end()){
                count+=rem[(sum%k + k)%k];
            }
            rem[(sum%k + k)%k]++;
        }
        return count;
    } 
};