class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        sort(target.begin() , target.end());
        sort(arr.begin() , arr.end());
        return arr == target;
    }
};