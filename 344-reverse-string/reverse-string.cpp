class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        uint_fast32_t left = 0;
        uint_fast32_t right = s.size()-1;
        while(left < right){
            swap(s[left] , s[right]);
            left++;
            right--;
        }
    }
};