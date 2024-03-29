class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0 , cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for(int &i:nums){
            if(cnt1==0 and i!=el2){
                cnt1 = 1;
                el1 = i;
            }
            else if(cnt2==0 and i!=el1){
                cnt2 = 1;
                el2 = i;
            }
            else if(i==el1) cnt1++;
            else if(i==el2) cnt2++;
            else{
                cnt1--; cnt2--;
            }
        }
        cnt1=0; cnt2=0;
        vector<int>ls;
        for(int &i:nums){
            if(i==el1) cnt1++;
            if(i==el2) cnt2++;
        }
        int mini = nums.size()/3 + 1;
        if(cnt1>=mini) ls.push_back(el1);
        if(cnt2>=mini) ls.push_back(el2);
        return ls;
    }
};