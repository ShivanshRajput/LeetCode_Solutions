class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int count = 0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(count>0){
                    count--;
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};