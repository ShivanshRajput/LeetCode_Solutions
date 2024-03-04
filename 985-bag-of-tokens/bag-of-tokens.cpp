class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        int maxscore = 0;
        while (low<=high){
            if(power>=tokens[low]){
                power-=tokens[low];
                score++;
                low++;
                maxscore = max(maxscore , score);
            }
            else if(score>0){
                power += tokens[high];
                score--;
                high--;
            }
            else{
                break;
            }
        }
        return maxscore;
    }
};