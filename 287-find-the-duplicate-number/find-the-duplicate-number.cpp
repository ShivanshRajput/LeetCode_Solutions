

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        ios_base::sync_with_stdio(false);  cin.tie(nullptr);
        for(int &i:arr){
            int num = abs(i);
            if(arr[num]<0){
                return num;
            }
            arr[num] = -arr[num];
        }
        return -1;
    }
};