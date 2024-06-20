class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j] = 'T';
        if(i>0 && board[i-1][j]=='O') dfs(i-1,j,board);
        if(j>0 && board[i][j-1]=='O') dfs(i,j-1,board);
        if(i<board.size()-1 && board[i+1][j]=='O') dfs(i+1,j,board);
        if(j<board[0].size()-1 && board[i][j+1]=='O') dfs(i,j+1,board);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[n-1][j]=='O') dfs(n-1,j,board);
        }
        for (int i=1;i<n-1;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][m-1]=='O') dfs(i,m-1,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='T') board[i][j] = 'O';
            }
        }
    }
};