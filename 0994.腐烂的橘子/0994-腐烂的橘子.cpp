class Solution {
private:
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0,freshnum=0;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m ; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j]==1){
                    freshnum++;
                }
            }
        }
        while(!q.empty()){
            int len=q.size();
            bool rotten=false;
            while(len--){
                int nr=q.front().first;
                int nc=q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int newRow=nr+dx[i];
                    int newCol=nc+dy[i];
                    if (newRow>=0&&newRow<m&&newCol>=0&&newCol<n&&grid[newRow][newCol]==1)
                    {
                        grid[newRow][newCol]=2;
                        q.push(make_pair(newRow,newCol));
                        freshnum--;
                        rotten=true;
                    }
                }
            }
            if (rotten)
            {
                cnt++;
            }
        }
        return freshnum>0? -1:cnt;
        
    }
};