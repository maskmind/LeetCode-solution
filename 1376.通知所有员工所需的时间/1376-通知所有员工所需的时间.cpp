class Solution {
public:
    vector<vector<int>> vec;
   // vector<bool> visted;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vec.resize(n);
   
        for (int i = 0; i <manager.size(); ++i)
        {
            if (i!=headID){
                vec[manager[i]].push_back(i);
            }
        }
         return dfs(headID,informTime);
    }
    int dfs(int headID,vector<int>& informTime){
        int res=0;
        //visted[headID]=true;
        for (int i = 0; i < vec[headID].size(); ++i)
        {
            
                res=max(res,dfs(vec[headID][i],informTime));
            
        }
        return res+informTime[headID];

    }
};