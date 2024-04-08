class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int circle=0 , square=0;
        for(int & x:students){
            if(x==0) circle++;
            else square++;
        }
        for(int & x :sandwiches){
            if(x==0){
                circle--;
                if(circle<0){
                    circle++;
                    break; 
                } 
            }
            else{
                square--;
                if(square<0){
                    square++;
                    break; 
                }
            }
        }
        return circle + square;
    }
};