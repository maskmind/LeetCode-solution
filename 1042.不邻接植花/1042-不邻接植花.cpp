class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> grid(N,vector<int>());
        //graph
        for (int i = 0; i < paths.size(); ++i)
        {
            grid[paths[i][0]-1].push_back(paths[i][1]-1);
            grid[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> answer(N,0);
        for (int i = 0; i < N; ++i)
        {
            set<int> s{1,2,3,4};
            for (int j = 0; j < grid[i].size() ; ++j)
            {
                s.erase(answer[grid[i][j]]);
            }
            answer[i]=*(s.begin());
        }
        return answer;
    }
};