

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        ios_base::sync_with_stdio(false);  cin.tie(nullptr);
        for(int i=0;i<arr.size();i++){
            int num = abs(arr[i]);
            if(arr[num]<0){
                return num;
            }
            arr[num] = -arr[num];
        }
        return -1;
    }
};