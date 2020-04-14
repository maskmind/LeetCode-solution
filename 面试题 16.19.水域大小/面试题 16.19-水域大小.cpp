class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> len;
        if (land.size()<1)
        {
            return len;
        }
        int m=land.size();
        int n=land[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (land[i][j]==0)
                {
                    len.push_back(dfs(land,i,j,m,n));
                }
            }
        }
        sort(len.begin(),len.end());
        return len;

    }
    int dfs(vector<vector<int>>&land,int row,int col,int m,int n){
        if (row<0||row>=m||col<0||col>=n||land[row][col]!=0)
        {
            return 0;
        }
        int cnt=0;
        land[row][col]=1;
        cnt=cnt+1;
        cnt+=dfs(land,row+1,col,m,n);
        cnt+=dfs(land,row-1,col,m,n);
        cnt+=dfs(land,row,col+1,m,n);
        cnt+=dfs(land,row,col-1,m,n);
        cnt+=dfs(land,row+1,col+1,m,n);
        cnt+=dfs(land,row+1,col-1,m,n);
        cnt+=dfs(land,row-1,col+1,m,n);
        cnt+=dfs(land,row-1,col-1,m,n);
        return cnt;
    }
};