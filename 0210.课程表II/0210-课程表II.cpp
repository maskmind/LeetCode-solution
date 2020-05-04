class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<bool> visited(numCourses,false);
        vector<int> res;
        vector<vector<int>> grid(numCourses,vector<int>());
        for(auto vec :prerequisites){
            //入度
            indegree[vec[0]]++;
            //学完 0可以学1
            grid[vec[1]].push_back(vec[0]);
        }
        queue<int> q;
        //没有先决条件
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty()){
            int idx=q.front();q.pop();
            visited[idx]=true;
            res.push_back(idx);
            for (int i = 0; i < grid[idx].size(); ++i)
            {
                indegree[grid[idx][i]]--;
                if (indegree[grid[idx][i]]==0&&!visited[grid[idx][i]])
                {
                    q.push(grid[idx][i]);

                }
            }
        }
        //bian li visited
        for (auto b:visited)
        {
            if (!b)
            {
                return vector<int>();
            }
        }
        return res;
        

    }
};