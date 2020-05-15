class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0)
        {
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size();
        int maxSize=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        //边界值处理
        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i]=='1')
            {
                dp[0][i]=1;
                maxSize=max(maxSize,dp[0][i]);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0]=='1')
            {
                dp[i][0]=1;
                maxSize=max(maxSize,dp[i][0]);
            }
        }
        
        for (int i = 1; i < m; ++i)
        {
            
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j]=='1')
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    maxSize=max(maxSize,dp[i][j]);
                }
            }
            
        }
        return maxSize*maxSize;

    }
};