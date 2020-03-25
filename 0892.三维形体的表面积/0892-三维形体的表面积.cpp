class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sur=0;
        int len=grid.size();
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                
                if(grid[i][j]>0){
                    // up and down
                    sur+=2;
                    //check around
                    //down
                    if (i+1>=0&&i+1<len)
                    {
                        sur+=max(grid[i][j]-grid[i+1][j],0);
                    }else{
                        sur+=max(grid[i][j],0);
                    }
                    //up
                    if (i-1>=0&&i-1<len)
                    {
                        sur+=max(grid[i][j]-grid[i-1][j],0);
                    }else{
                        sur+=max(grid[i][j],0);
                    }
                    //right 
                    if (j+1>=0&&j+1<len)
                    {
                        sur+=max(grid[i][j]-grid[i][j+1],0);
                    }else{
                        sur+=max(grid[i][j],0);
                    }
                    //left
                     if (j-1>=0&&j-1<len)
                    {
                        sur+=max(grid[i][j]-grid[i][j-1],0);
                    }else{
                        sur+=max(grid[i][j],0);
                    }
                }
            }                
        }
        return sur;
    }
};