
class Solution {
    typedef pair<int,int> pos;
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (auto i = 0; i < board.size(); ++i)
        {
            for (auto j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j]==word[0])
                {
                    vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));                    
                    if (dfs(board,vis,i,j,word,0))
                    {
                        return true;
                    }
                }
            }
        }
       
       
        return false;
    }


    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int row,int col,string& word,int index){
        if (board[row][col]!=word[index]){
            return false;
        }else if (index==word.length()-1){
            return true;
        }
        vis[row][col]=true;
        
        for (int i = 0; i < 4; ++i)
        {
            int xx=row+dx[i];
            int yy=col+dy[i];

            if (xx>=0&&xx<board.size()&&yy>=0&&yy<board[0].size()&&!vis[xx][yy])
            {   
                if (dfs(board,vis,xx,yy,word,index+1))
                {
                    return true;
                }
            }
        }
        vis[row][col]=false;
        return false;

    }


};

