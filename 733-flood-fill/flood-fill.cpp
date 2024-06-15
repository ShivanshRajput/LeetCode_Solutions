class Solution {
private:
void dfs(int start , int row ,int col , vector<vector<int>>& image ,int color){
    image[row][col] = color;
    if(row>0 && image[row-1][col]==start) dfs(start , row-1 , col , image , color); 
    if(col>0 && image[row][col-1]==start) dfs(start , row , col-1 , image , color); 
    if(row<image.size()-1 && image[row+1][col]==start) dfs(start , row+1 , col , image , color); 
    if(col<image[0].size()-1 && image[row][col+1]==start) dfs(start , row , col+1 , image , color); 
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if(start!=color) dfs(start , sr , sc , image ,color);
        return image;
    }
};