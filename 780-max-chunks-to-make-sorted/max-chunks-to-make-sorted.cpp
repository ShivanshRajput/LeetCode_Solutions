class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax = arr;
        vector<int> rightMin = arr;
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i] , leftMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightMin[i] = min(rightMin[i] , rightMin[i+1]);
        }
        int chunkCount = 0;
        for(int i=0;i<n;i++){
            if(i==0 || leftMax[i-1] < rightMin[i]) chunkCount++;
        }
        return chunkCount;
    }
};