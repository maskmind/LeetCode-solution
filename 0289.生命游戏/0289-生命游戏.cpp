class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size()==0)
        {
            return ;
        }
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>> arrcopy(row,vector<int>(col,0));
        //copy board
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                arrcopy[i][j]=board[i][j];
            }
        }
        int direct[3]={0,1,-1};
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int liveCellCnt=0;
                //direct chose
                for (int dir_i = 0; dir_i < 3; ++dir_i)
                {
                    for (int dir_j = 0; dir_j < 3; ++dir_j)
                    {
                        // dir_i dir_j !=0
                        if (!(direct[dir_i]==0&&direct[dir_j]==0))
                        {
                            int newRow=i+direct[dir_i];
                            int newCol=j+direct[dir_j];
                            //edge
                            if ((newRow<row&&newRow>=0)&&(newCol<col&&newCol>=0)&&arrcopy[newRow][newCol]==1)
                            {
                                liveCellCnt+=1;
                            }
                        }
                    }
                }
                if (arrcopy[i][j]==1&&(liveCellCnt<2||liveCellCnt>3))
                {
                    board[i][j]=0;
                }
                if (arrcopy[i][j]==0&&liveCellCnt==3)
                {
                    board[i][j]=1;
                }
            }
        }

    }
};