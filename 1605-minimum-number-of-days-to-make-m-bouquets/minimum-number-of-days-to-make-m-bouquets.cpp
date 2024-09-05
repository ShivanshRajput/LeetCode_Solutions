class Solution {
public:
    bool bouquetPossible(vector<int>&bloomDay , int m , int k , int day){
        int bouquetCount = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            while (i < n && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }
            if (count == k) {  // bouquet formed here
                bouquetCount++;
                i--;
            }
            if (bouquetCount >= m) {  // m bouquets are formed 
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        int min_days = high;
        while(low<=high){
            int mid = (low + high)/2;
            if(bouquetPossible(bloomDay , m , k , mid)){
                min_days = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return min_days;
    }
};