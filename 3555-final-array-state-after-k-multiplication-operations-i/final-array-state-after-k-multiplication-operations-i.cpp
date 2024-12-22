class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i] , i});
        }
        while(k--){
            int minid = pq.top().second;
            pq.pop();
            nums[minid] *= multiplier;
            pq.push({nums[minid] , minid});
        }
        return nums;
    }
};