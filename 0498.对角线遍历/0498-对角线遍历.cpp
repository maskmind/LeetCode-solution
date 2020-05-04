class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> rt;
        int m=matrix.size();
        if (m<1)
        {
            return rt;
        }
        int n=matrix[0].size();
        if (n<1)
        {
            return rt;
        }
        int level=m+n-1;
        for (int curlevel = 0; curlevel < level; ++curlevel)
        {
            int row_begin = curlevel + 1 <= n ? 0 : curlevel + 1 - n;
            int row_end =  curlevel + 1 >= m ? m - 1 : curlevel;
            if (curlevel % 2 == 1){
                for (int i = row_begin ; i <= row_end ; i++)
                    rt.push_back(matrix[i][curlevel - i]);
            }
            else{
                for (int i = row_end ; i >= row_begin ; i--)
                    rt.push_back(matrix[i][curlevel - i]);
            }
        }
        return rt;

    }
};