class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> decrease;
        deque<int> increase;
        int ans = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            int num = nums[right];
            while(!decrease.empty() && num>decrease.back()){
                decrease.pop_back();
            }
            decrease.push_back(num);
            while(!increase.empty() && num<increase.back()){
                increase.pop_back();
            }
            increase.push_back(num);

            while(decrease.front() - increase.front() > limit){
                if(decrease.front() == nums[left]){
                    decrease.pop_front();
                }
                if(increase.front() == nums[left]){
                    increase.pop_front();
                }
                left++;
            }
            ans = max(ans , right-left+1);
        }
        return ans;
    }
};