class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int prefixSum = 0 , sortedSum = 0;
        int chunkCount = 0;
        for(int i=0;i<n;i++){
            prefixSum += arr[i];
            sortedSum += i;
            if(prefixSum == sortedSum) chunkCount++; 
        }
        return chunkCount;
    }
};