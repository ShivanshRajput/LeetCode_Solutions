class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long xorsum = 0;
        for(int&i:nums){
            xorsum^=i;
        }
        long diff = (xorsum & (-xorsum));
        int num1 = 0;
        int num2 = 0;
        for(int&i:nums){
            if(i&diff){
                num1^=i;
            }
            else{
                num2^=i;
            }
        }
        return {num1 , num2};
    }
};