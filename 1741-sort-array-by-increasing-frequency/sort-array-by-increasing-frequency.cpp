class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int_fast16_t freq[201] = {};
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+100]++;
        }
        sort(nums.begin() , nums.end() , [&](int_fast16_t a, int_fast16_t b){
            if(freq[a+100] == freq[b+100]){
                return a>b;
            }
            return freq[a+100]<freq[b+100];
        } );
        return nums;
    }
};