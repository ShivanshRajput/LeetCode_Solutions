class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st (wordList.begin() , wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(word == endWord) return depth;
            for(int i=0;i<word.size();i++){
                char temp = word[i];
                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push({word , depth+1});
                        st.erase(word);
                    }
                    
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};