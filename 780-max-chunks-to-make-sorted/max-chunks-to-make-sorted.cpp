class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // using monotonic stack...
        stack<int> mono;
        for(int &it: arr){
            if(mono.empty() || it > mono.top()){
                mono.push(it);
            }
            else{
                int maxYet = mono.top();
                while(!mono.empty() && it < mono.top()){
                    mono.pop();
                }
                mono.push(maxYet);
            }
        }
        return mono.size();
    }
};