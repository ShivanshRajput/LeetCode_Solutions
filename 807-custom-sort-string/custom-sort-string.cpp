class Solution {
public:
    string customSortString(string order, string s) {

        int freq[26]={};
        string ans="";
        for(char &c:s){
            freq[c-'a']++;
        }
        for(char &c:order){
            ans.append(freq[c-'a'] , c);
            freq[c-'a']=0;
        }
        for(int i=0;i<26;i++){
            ans.append(freq[i] , i+'a');
        }
        return ans;
    }
};