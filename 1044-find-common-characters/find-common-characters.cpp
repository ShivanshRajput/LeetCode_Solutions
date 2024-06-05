class Solution {
public:
    vector<int> countFreq(string &s){
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        return freq;
    }

    vector<int>intersection(const vector<int> &a ,const vector<int> &b){
        vector<int> res(26,0);
        for(int i=0;i<26;i++){
            res[i] = min(a[i] , b[i]);
        }
        return res;
    }

    vector<string> commonChars(vector<string>& words) {
        vector<int> last = countFreq(words[0]);
        for(int i=0;i<words.size();i++){
            last = intersection(last , countFreq(words[i]));
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(last[i]>0){
                ans.push_back(string(1 , 'a'+i));
                last[i]--;
            }
        }
        return ans;
    }
};