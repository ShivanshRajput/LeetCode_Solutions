class Solution {
public:
    bool judgeCircle(string moves) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int xaxis = 0 , yaxis = 0;
        for(char& c: moves){
            if(c=='U') xaxis++;
            else if(c=='D') xaxis--;
            else if(c=='R') yaxis++;
            else yaxis--;
        }
        return (xaxis==0 && yaxis==0);
    }
};