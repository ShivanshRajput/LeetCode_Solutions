class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int hapi = 0;
        int extraHapi = 0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]){
                hapi += customers[i];
            }
            else if(i<minutes){
                extraHapi += customers[i];
            }
        }
        int maxExtraHapi = extraHapi;
        for(int i=minutes;i<n;i++){
            extraHapi += customers[i]*grumpy[i] - customers[i-minutes]*grumpy[i-minutes];
            maxExtraHapi = max(maxExtraHapi , extraHapi);
        }
        return maxExtraHapi + hapi;
    }
};