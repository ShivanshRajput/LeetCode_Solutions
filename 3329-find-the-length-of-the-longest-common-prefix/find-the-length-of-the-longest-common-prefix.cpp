class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string ,int> freq;
        for (int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            for(int j=0;j<=s.size();j++){
                freq[s.substr(0,j)]++;
            }
        }
        int maxl=0;
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            for(int j=0;j<=s.size();j++){
                if(freq.find(s.substr(0,j)) != freq.end())
                    maxl=max(maxl,j);
                else
                    break;
            }
            
        }
        return maxl;
    }
};