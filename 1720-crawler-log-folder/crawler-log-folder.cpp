class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>path;
        for(string &s:logs){
            if(s=="../"){
                if(!path.empty()){
                    path.pop();
                }
            }
            else if(s=="./"){
                continue;
            }
            else{
                path.push(1);
            }
        }
        return path.size();
    }
};