class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int,string> mpp;
        for(int i=0;i<n;i++){
            mpp[heights[i]] = names[i];
        }
        sort(heights.begin() , heights.end() , greater<int>());
        for(int i=0;i<n;i++){
            names[i] = mpp[heights[i]];
        }
        return names;
    }
};