class Solution {
public:
    bool bouquetPossible(vector<int>&bloomDay , int m , int k , int day){
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }
            if (count == k) {
                total++;
                i--;
            }
            if (total >= m) {
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if((long long)m*k > bloomDay.size()) return -1;
        int low = 1 , high = 1e9;
        while(low<high){
            int mid = (low + high)/2;
            if(bouquetPossible(bloomDay , m , k , mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};