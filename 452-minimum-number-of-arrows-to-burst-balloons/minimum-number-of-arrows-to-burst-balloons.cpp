class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base:: sync_with_stdio(0);
        cin.tie(NULL);
        sort(points.begin() , points.end());
        int y = points[0][1];
        int arrows=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0] > y){
                arrows++;
                y = points[i][1];
            }
            y = min(y , points[i][1]);
        }
        return arrows;
    }
};