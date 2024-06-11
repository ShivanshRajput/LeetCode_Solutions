class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> freq;
        for(int &i:arr1){
            freq[i]++;
        }
        vector<int>ans(arr1.size());
        int index = 0;
        for(int &i:arr2){
            while(freq[i]>0){
                ans[index++] = i;
                freq[i]--;
            }
        }
        int j = index;
        for(auto &i: freq){
            while(i.second>0){
                ans[j++] = i.first;
                i.second--;
            }
        }
        sort(ans.begin()+index , ans.end());
        return ans;
    }
};