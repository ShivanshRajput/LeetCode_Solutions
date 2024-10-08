class Solution {
private:
    void findCombination(int ind , int target , vector<int>& arr , vector<vector<int>>&ans , vector<int> &list){
        if(target == 0){
            ans.push_back(list);
            return ;
        }
        for(int i=ind; i<arr.size();i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            list.push_back(arr[i]);
            findCombination(i+1 , target - arr[i] , arr , ans , list);
            list.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> list;
        findCombination(0 , target  , candidates , ans , list);
        return ans;
    }
};