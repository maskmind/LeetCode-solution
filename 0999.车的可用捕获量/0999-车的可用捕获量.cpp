class Solution {
public:
 
    int numRookCaptures(vector<vector<char>>& board) {
        // find R
        int x,y;
        /*for (x = 0; x < 8; x++)
        {
            for (y = 0; y < 8; y++)
            {
                if (board[x][y]=='R')
                {
                    break;
                }
            
            }
        }*/
        //v[x][y]==R
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }


        int dr[]{0, 1, 0, -1};
        int dc[]{1, 0, -1, 0};
        
        int sum=0;
        
        for (int k = 0; k < 4; ++k) {
            int nr = x + dr[k];
            int nc = y + dc[k];
            int tmp=0;
            while(nr<8&&nr>=0&&nc<8&&nc>=0){
                if(board[nr][nc]=='B'){
                    break;
                }
                else if (board[nr][nc]=='p')
                {
                    tmp=1;
                    break;
                }
                nr+=dr[k];
                nc+=dc[k];
                
            }
            sum+=tmp;                        
        }
        return sum;
    }
};