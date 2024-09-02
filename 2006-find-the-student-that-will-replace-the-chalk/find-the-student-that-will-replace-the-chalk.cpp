class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n =  chalk.size();
        long long sum = accumulate(chalk.begin() , chalk.end() , 0ll);
        k%=sum;
        for(int i=0;i<n;i++){
            if(chalk[i]>k){
                return i;
            }
            else{
                k-=chalk[i];
            }
        }
        return 0;
    }
};