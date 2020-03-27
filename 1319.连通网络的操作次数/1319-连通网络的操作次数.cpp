class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1)
        {
            return -1;
        }
        //resize map
        edge.resize(n);
        /*
        *³¬ÄÚ´æ
        for (int i = 0; i < n; ++i)
        {
            vector<int> init(n,0);
            edge.push_back(init);
        }
        */
        // input map
        for (vector<int> v:connections)
        {
            //ÎÞÏòÍ¼
            edge[v[0]].push_back(v[1]);
            edge[v[1]].push_back(v[0]);
        }
        //resize visited
        visited.resize(n);
        int partNum=0;
        for (int i = 0; i < n; ++i)
        {
            if(!visited[i]){
                partNum++;
                dfs(i);
            }
        }
        return partNum-1;

    }
    /*void dfs(int row){
        visited[row]=true;
        for (int i = 0; i < edge[row].size(); ++i)
        {
            if (!visited[edge[row][i]])
            {
                dfs(edge[row][i]);
            }
        }
    }*/
    void dfs(int row){
        visited[row]=true;
        stack<int> s;
        s.push(row);
        while(!s.empty()){
            int root=s.top();
            for(int nt:edge[root]){
            
                if(!visited[nt]){
                    visited[nt]=true;
                    s.push(nt);
                    break;
                }
            }
            int cnt=0;
            int tmp=s.top();
            for(int item:edge[tmp]){
                if(visited[item])cnt++;
            }
            if (cnt==edge[tmp].size())
            {
                s.pop();
            }
            
        }
    }
private:
    vector<vector<int>> edge;
    vector<bool> visited;
};