class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char c: s){
            freq[c]++;
        }
        int midChar =0;
        int sideChar =0;
        for(char c = 'a';c<='z';c++){
            if(freq[c]%2) midChar = 1;
            sideChar+=freq[c]/2;
        }
        for(char c = 'A';c<='Z';c++){
            if(freq[c]%2) midChar = 1;
            sideChar+=freq[c]/2;
        }
        return 2*sideChar + midChar;
    }
};