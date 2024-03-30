class Solution {
public:
    int subarraysUptoKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int i=0;
        int count=0;
        for(int j=0;j<n;j++){
            freq[nums[j]]++;
            while(freq.size()>k and i<=j){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysUptoKDistinct(nums , k) - subarraysUptoKDistinct(nums , k-1);
    }
};