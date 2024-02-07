class Solution {
public:
    string frequencySort(string s) {
        int freq[75]={0};
        for(auto &x:s){
            freq[x-'0']++;
        }
        vector<pair<int,int>> vp;
        for(int i=0; i<75;i++){
            if(freq[i]!=0){
                vp.push_back({freq[i] , i});
            }
        }
        sort(vp.begin() , vp.end() , greater<pair<int,int>>());
        string ans="";
        for(auto &i : vp){
            while(i.first--){
                ans+=(char(i.second+'0'));
            }
        }
        return ans;
    }
};