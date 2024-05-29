class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int carry = 0 , steps = 0;
        for(int i=n-1;i>0;i--){
            if(s[i]=='1'){
                if(carry==0){
                    carry = 1;
                    steps+=2;
                }
                else{
                    steps+=1;
                }
            }
            else{
                if(carry==0){
                    steps+=1;
                }
                else{
                    steps+=2;
                }
            }
        }
        return steps + carry;
    }
};