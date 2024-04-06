class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        int maxc=0;
        for(int i : st){
            if(st.find(i-1)==st.end()){
                int n = i , count=1;
                while(st.find(++n)!=st.end()) count++;
                maxc = max(maxc , count);
            }
        }
        return maxc;
    }
};