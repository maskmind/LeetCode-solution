class Solution {
    int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dy[8] = { 1, 0,-1, 1,-1, 1, 0,-1};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row=click[0];
        int col=click[1];
        int m=board.size();
        if (m<1)
        {
            return board;
        }
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        if (board[row][col]=='M')
        {
            board[row][col]='X';
        }else{
            dfs(board,visited,row,col,m,n);
        }
        return board;

    }
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int row,int col,int m,int n){
        if (row<0||row>=m||col<0||col>=n||visited[row][col]==true)
        {
            return ;
        }
        visited[row][col]=true;
        int minesRound=0;
        for (int i = 0; i < 8; ++i)
        {
            int newRow=dx[i]+row;
            int newCol=dy[i]+col;
            if (newRow>=0&&newRow<m&&newCol>=0&&newCol<n&&board[newRow][newCol]=='M')
            {
                minesRound++;
            }
        }
        if (minesRound>0)
        {
            board[row][col]=minesRound+'0';
            return ;
        }else{
            board[row][col]='B';
            for (int i = 0; i < 8; ++i)
            {
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                if (newRow>=0&&newRow<m&&newCol>=0&&newCol<n&&board[newRow][newCol]=='E'&&!visited[newRow][newCol]){
                    dfs(board,visited,newRow,newCol,m,n);
                }
            }
        }       

    }
};