class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> grid[N+1];
        for (int i = 0; i < trust.size(); ++i)
        {
            grid[trust[i][0]].push_back(trust[i][1]);
        }
        vector<int> cadid;
        for (int i = 1; i < N+1; ++i)
        {
            if (grid[i].size()==0)
            {
                cadid.push_back(i);
            }
        }
        //对候选人遍历
        for (int i = 0; i < cadid.size(); ++i)
        {
            //确定是不是每个人都相信
            //cout<<cadid[i];

            for (int j = 1; j < N+1; ++j)
            {
                //youren buxiangxin houxuan 
                if(j!=cadid[i]&&find(grid[j].begin(),grid[j].end(),cadid[i])==grid[j].end()){
                    cadid[i]=-1;
                    break;
                }
            }
            //cout<<cadid[i];
        }
        int cnt=0;
        int rt=-1;
        for (int i = 0; i < cadid.size(); ++i)
        {
            if (cadid[i]!=-1)
            {
                ++cnt;
                rt=cadid[i];
            }
        }
        if (cnt==1)
        {
            return rt;
        }else{
            return -1;
        }

    }
};