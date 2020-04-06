class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int len=grid.size();
        vector<int> S(len,0);
        vector<int> V(len,0);
        for (int row = 0; row < len; ++row)
        {
            for (int col = 0; col < len; ++col)
            {
                V[row]=max(V[row],grid[row][col]);
                S[col]=max(S[col],grid[row][col]);
            }
        }
        int cnt=0;
        for (int i = 0; i <len ; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                cnt+=min(V[i],S[j])-grid[i][j];
            }
        }
        return cnt;


    }
};