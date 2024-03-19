class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int freq[26]={};
        for(char t:tasks){
            freq[t-'A']++;
        }
        sort(freq , freq+26);
        int chunk = freq[25] - 1;
        int idel = chunk * n;
        for(int i=24;i>=0;i--){
            idel -= min(chunk , freq[i]);
        } 
        if(idel < 0){
            return tasks.size();
        }
        return tasks.size() + idel;
    }
};