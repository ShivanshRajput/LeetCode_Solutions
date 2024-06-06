class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        map<int,int> freq;
        for(int &c : nums){
            freq[c]++;
        }
        for(auto &it : freq){
            if(it.second > 0){
                int card = it.first;
                int count = it.second;
                for(int i=0;i<k;i++){
                    freq[card+i]-=count;
                    if(freq[card+i]<0){
                        return false;
                    }
                }

            }
        }
        return true;
    }
};