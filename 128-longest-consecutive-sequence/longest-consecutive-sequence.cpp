class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if(nums.size()==0) return 0;
        int mxcnt = 1;
        unordered_set<int>st(nums.begin() , nums.end());
        for(int x:st){
            if(st.find(x-1)==st.end()){
                int term = x , cnt = 1;
                while(st.find(++term)!=st.end()) cnt++;
                mxcnt = max(mxcnt , cnt);
            }
        }
        return mxcnt;
    }
};