class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int> freq;
        for(int &c : hand){
            freq[c]++;
        }
        for(auto &it : freq){
            if(it.second > 0){
                int card = it.first;
                int count = it.second;
                for(int i=0;i<groupSize;i++){
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