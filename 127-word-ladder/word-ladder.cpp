class Solution {
private:
    bool isValid(string &s,string &t){
        if(s.size()!=t.size()) return false;
        int differ_count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                differ_count++;
            }
        }
        return (differ_count == 1);
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(beginWord == endWord) return 0;
        int endIdx = -1;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                endIdx = i;
                break;
            }
        }
        if(endIdx==-1) return 0;
        vector<bool>start(n,false);
        bool validStart = false;
        for(int i=0;i<n;i++){
            if(isValid(beginWord , wordList[i])){
                start[i] = true;
                validStart = true;
            }
        }
        if(!validStart) return 0;

        vector<int>distance(n,1e9);
        queue<int>q;
        distance[endIdx] = 0;
        q.push(endIdx);
        while(!q.empty()){
            int node = q.front();
            for(int &i:adj[node]){
                if(distance[i]==1e9){ // if not been visited
                    distance[i] = distance[node] + 1;
                    q.push(i);
                }
            }
            q.pop();
        }
        int minDistance = 1e9;
        for(int i=0;i<n;i++){
            // cout<<start[i]<<" "<<distance[i]<<endl;
            if(start[i]){
                minDistance = min(minDistance , distance[i]);
            }
        }
        if(minDistance == 1e9) return 0;
        return minDistance + 2;
    }
};