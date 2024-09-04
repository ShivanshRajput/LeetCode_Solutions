class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        set<pair<int,int>> obs ; 
        for(auto &it : obstacles){
            obs.insert({it[0] , it[1]});
        }
        char dirn[4] = {'N' , 'E' , 'S' , 'W'}; 
        int dir = 0;
        int X=0,Y=0;
        int maxDist = 0;
        for(int & c: commands){
            if(c<0){
                if(c==-1){
                    dir = (dir + 1)%4;
                }
                else{
                    dir = (dir + 3)%4;
                }
            }
            else{
                while(c--){
                    // cout<<"X"<<X<<" "<<"Y"<<Y<<endl;
                    if(dir == 0){  // facing north
                        if(obs.find({X,Y+1}) == obs.end()){
                            Y++;
                        }
                    }
                    else if(dir==1){  // facing east
                        if(obs.find({X+1,Y}) == obs.end()){
                            X++;
                        }
                    }
                    else if(dir==2){  // facing south
                        if(obs.find({X,Y-1}) == obs.end()){
                            Y--;
                        }
                    }
                    else{  // faicng west
                        if(obs.find({X-1,Y}) == obs.end()){
                            X--;
                        }
                    }
                    maxDist = max(maxDist , X*X+Y*Y);
                }
            }
        }
        return maxDist;
    }
};