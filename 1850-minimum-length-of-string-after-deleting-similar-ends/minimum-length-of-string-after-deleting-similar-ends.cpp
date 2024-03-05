class Solution {
public:
    int minimumLength(string s) {
        int low=0 , high=s.size()-1;
        while(low<high and s[low] == s[high]){
            char c = s[low];
            while(low<=high and s[low]==c) low++;
            while(high>=low and s[high]==c) high--;
        }
        return high - low + 1;
    }
};