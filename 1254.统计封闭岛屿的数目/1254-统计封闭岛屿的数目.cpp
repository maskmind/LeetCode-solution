class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int partNum=0;
        for (int i = 0; i <grid.size(); ++i)
        {
            for (int j = 0; j <grid[i].size(); ++j)
            {
                //grid[i][j]=0ʱΪ½�أ�dfs
                if (grid[i][j]==0)
                {
                    partNum+=dfs(i,j,grid);
                }
            }
        }
        return partNum;
    }
    int dfs(int x,int y,vector<vector<int>>& grid){
        if (x<0||x>=grid.size()||y<0||y>=grid[x].size())
        {
            return 0;
        }
        if (grid[x][y]==1)
        {
            return 1;
        }
        grid[x][y]=1;
        int res=1;
        int dx[]{0, 1, 0, -1};
        int dy[]{1, 0, -1, 0};
        for (int i = 0; i < 4; ++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            res=min(res,dfs(xx,yy,grid));
        }
        return res;
    }
};