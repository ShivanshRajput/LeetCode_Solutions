class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> sums;
        sums[0]=-1;
        int cum=0 , res=0;
        for(int i=0;i<nums.size();i++){
            cum+=(nums[i])?(1):(-1);
            if(sums.find(cum)!=sums.end()){
                res=max(res , i-sums[cum]);
            } 
            else{
                sums[cum]=i;
            }
        }
        return res;
    }
};