class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // using minElement...
        int n = arr.size();
        int mini = n , chunks = 0;
        for(int i=n-1;i>=0;i--){
            mini = min(mini , arr[i]);
            if(mini == i) chunks++;
        }
        return chunks;
    }
};