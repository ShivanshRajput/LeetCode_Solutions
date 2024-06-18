class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int jobs = difficulty.size();
        int workers = worker.size();
        int maxDifficulty = *max_element(difficulty.begin() , difficulty.end());
        // declaring array to hold all possible difficulties
        vector<int> maxProfitUptoDifficulty(maxDifficulty+1,0);
        for(int i=0;i<jobs;i++){  
            maxProfitUptoDifficulty[difficulty[i]] = max(maxProfitUptoDifficulty[difficulty[i]] , profit[i]);
        }
        // prefix sum (like not exactly sum but you get the notion)
        for(int i=1;i<=maxDifficulty;i++){
            maxProfitUptoDifficulty[i] = max(maxProfitUptoDifficulty[i] , maxProfitUptoDifficulty[i-1]);
        }
        // calculating total profit using vector 'maxProfitUptoDifficulty'
        int totalProfit = 0;
        for(int & strength : worker){   // considering each worker's strength
            if(strength > maxDifficulty){    // for cases of engineers one day before exam 
                totalProfit += maxProfitUptoDifficulty[maxDifficulty];
            }
            else{                            // for cases of normal days
                totalProfit += maxProfitUptoDifficulty[strength];
            }
        }
        return totalProfit;
    }
};