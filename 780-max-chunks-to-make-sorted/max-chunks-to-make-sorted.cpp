class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // using maxElement...
        int n = arr.size();
        int maxi = 0 , chunks = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi , arr[i]);
            if(maxi == i) chunks++;
        }
        return chunks;
    }
};