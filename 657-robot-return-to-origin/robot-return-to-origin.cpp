class Solution {
public:
    bool judgeCircle(string moves) {
        int xaxis = 0 , yaxis = 0;
        for(char& c: moves){
            xaxis+=(c=='U');
            xaxis-=(c=='D');
            yaxis+=(c=='R');
            yaxis-=(c=='L');
        }
        return (xaxis==0 && yaxis==0);
    }
};