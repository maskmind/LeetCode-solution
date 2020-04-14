class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size()<1)
        {
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        int maxAre=0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]==1)
                {
                    maxAre=max(maxAre,dfs(grid,i,j,m,n));
                }
            }
        }
        return maxAre;

    }
    int dfs(vector<vector<int>> &grid,int row,int col,int m,int n){
        if (row<0||row>=m||col<0||col>=n||grid[row][col]==0||grid[row][col]==-1)
        {
            return 0;
        }
        int maxLevel=0;
        maxLevel+=1;
        grid[row][col]=0;
        maxLevel+=dfs(grid,row+1,col,m,n);
        maxLevel+=dfs(grid,row-1,col,m,n);
        maxLevel+=dfs(grid,row,col+1,m,n);
        maxLevel+=dfs(grid,row,col-1,m,n);
        //grid[row][col]=1;
        return maxLevel;
    }
};