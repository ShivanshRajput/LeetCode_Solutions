class Solution {
private:
    bool possible(int capacity , vector<int>&weights , int days){
        int sum = 0;
        int daycnt = 1;
        for(int &it: weights){
            if(sum+it<=capacity){
                sum += it;
            }
            else{
                daycnt++;
                sum = it;
            }
        }
        return daycnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin() , weights.end() , 0);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(mid , weights , days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};