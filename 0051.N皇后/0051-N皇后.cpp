class Solution {
    vector<vector<string>> res;
    vector<string> resInput;
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        getResult(str,0,n);
        return res;

        
    }
    void getResult(string &str,int row,int n){
        if (resInput.size()==n)
        {
            res.push_back(resInput);
            return ;
        }
        for (int i = 0; i < n; ++i)
        {
            //每行第i个位置
            if (check(row,i,n))
            {
                str[i]='Q';
                resInput.push_back(str);
                str[i]='.';
                getResult(str,row+1,n);
                //not corrcet back
                resInput.pop_back();
            }
        }
    }
    bool check(int row,int col,int n){
        
        for(int i = 1; i <= row ; ++i)
        {
            if(col - i >= 0 && resInput[row - i][col - i] == 'Q')
                return false;
            if(col + i < n && resInput[row - i][col + i] == 'Q')
                return false;
            if(resInput[row - i][col] == 'Q')
                return false;
        }
        return true;

    }
};