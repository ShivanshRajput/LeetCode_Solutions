class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={};
        for(int &x:nums){
            freq[x]++;
        }
        int maxf = 0;
        for(int i=0;i<=100;i++){
            maxf = max(maxf , freq[i]);
        }
        int ans=0;
        for(int i=0;i<=100;i++){
            if(freq[i]==maxf){
                ans+=maxf;
            }
        }
        return ans;
    }
};