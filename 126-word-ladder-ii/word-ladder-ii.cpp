class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string beg;
    int sz;
private:
    void dfs(string word , vector<string>&seq){
        if(word == beg){
            reverse(seq.begin() , seq.end());
            ans.push_back(seq);
            reverse(seq.begin() , seq.end());
            return;
        }
        int steps = mp[word];
        for(int i=0;i<sz;i++){
            char og = word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(mp.find(word)!=mp.end() && mp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word , seq);
                    seq.pop_back();
                }
            }
            word[i] = og;
        }

    }
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        sz = beginWord.size();
        beg = beginWord;
        unordered_set<string> st (wordList.begin() , wordList.end());
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        mp[beginWord] = 0;
        while(!q.empty()){
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<sz;i++){
                char og = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps+1;
                    }
                }
                word[i] = og;
            }
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string> seq = {endWord};
            dfs(endWord , seq);
        }
        return ans;
    }
};