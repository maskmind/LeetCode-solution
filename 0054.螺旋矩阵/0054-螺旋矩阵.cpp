class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size()<1)
        {
            return res;
        }
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        while(true){
            //行 向右
            for (int i = left; i <= right; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            //去掉第一行
            if (++top>bottom)
            {
                break;
            }
            //向下
            for (int i = top; i <= bottom ; ++i)
            {
                res.push_back(matrix[i][right]);
            }
            //去掉最后一列
            if (--right<left)
            {
                break;
            }
            //向左
            for (int i = right; i >= left ; --i)
            {
                res.push_back(matrix[bottom][i]);
            }
            //去掉最后一行
            if (--bottom<top)
            {
                break;
            }
            //向上
            for (int i = bottom; i >= top ; --i)
            {
                res.push_back(matrix[i][left]);
            }
            //去掉第一列
            if (++left>right)
            {
                break;
            }
        }
        return res;
    }
};