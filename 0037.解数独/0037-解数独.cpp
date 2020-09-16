class Solution {
public:
    vector<set<int>> ROW,COL,BLOCK;

    void update(vector<vector<char>>&board){
        set<int> compare={1,2,3,4,5,6,7,8,9};
        for (int i = 0; i < 9; ++i)
        {
            ROW.push_back(compare);
            COL.push_back(compare);
            BLOCK.push_back(compare);
        }
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j]!='.')
                {
                    int val=board[i][j]-'0';
                    ROW[i].erase(val),COL[j].erase(val);
                    BLOCK[i/3+j/3*3].erase(val);
                }
            }
        }
        return ;
    }

    bool isVaild(const int& row ,const int& col ,int num,vector<vector<char>>& board){
        if (ROW[row].find(num)!=ROW[row].end()&&COL[col].find(num)!=COL[col].end()&&BLOCK[row/3+col/3*3].find(num)!=BLOCK[row/3+col/3*3].end())
        {
            return true;
        }
        return false;
    }
    
    int pflag=0;

    void dfs(vector<vector<char>>& board,int count){
        if (count==81)
        {
            pflag=1;
            return;
        }
        int i=count/9,j=count%9;

        if (board[i][j]=='.')
        {
            for (int k = 1; k < 10; ++k)
            {
                if(isVaild(i,j,k,board)){
                    ROW[i].erase(k),COL[j].erase(k),BLOCK[i/3+j/3*3].erase(k);
                    board[i][j]=k+'0';
                    dfs(board,count+1);
                    if(!pflag){
                        ROW[i].insert( k), COL[j].insert( k), BLOCK[ i /3 + j/3*3].insert( k);
                        board[i][j] = '.';
                    }else{
                        return ;
                    }
                }

            }
        }else{
            dfs(board,count+1);
        }
        return ;

    }
    void solveSudoku(vector<vector<char>>& board) {
        update(board);
        dfs(board,0);

    }
};
