class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // technique used: flattening of 2d array
        int n=matrix.size() , m=matrix[0].size();
        int low=0 , high=n*m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m , col = mid%m;
            if(target==matrix[row][col]){
                return true;
            }
            if(target<matrix[row][col]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};