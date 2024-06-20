class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        for (int j=0;j<m;j++){
            if(board[0][j]=='O') q.push({0,j});
            if(board[n-1][j]=='O') q.push({n-1,j});
        }
        for (int i=1;i<n-1;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            board[i][j] = 'T';
            if(i>0 && board[i-1][j]=='O') q.push({i-1,j});
            if(j>0 && board[i][j-1]=='O') q.push({i,j-1});
            if(i<n-1 && board[i+1][j]=='O') q.push({i+1,j});
            if(j<m-1 && board[i][j+1]=='O') q.push({i,j+1});
            q.pop();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='T') board[i][j] = 'O';
            }
        }
    }
};