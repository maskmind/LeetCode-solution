class Solution {
    struct Node
    {
        int num;
        int weight;
        Node(int _num,int _weight):num(_num),weight(_weight){};
    };

    typedef pair<int,int> location;

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<Node> grid[n];
        for (int i = 0; i < edges.size(); ++i)
        {
            grid[edges[i][0]].push_back(Node(edges[i][1],edges[i][2]));
            grid[edges[i][1]].push_back(Node(edges[i][0],edges[i][2]));

        }
        location loc(0x3f3f3f,-1);
        for (int i = 0; i < n; ++i)
        {
            vector<bool> visited(n,false);
            vector<int> dist(n,INT_MAX);
            dijkstra(grid,dist,visited,i,n);
            int cnt=0;
            for (int j = 0; j < n; ++j)
            {
                if (dist[j]<=distanceThreshold)
                {
                    ++cnt;
                }
            }
            if (cnt<=loc.first)
            {
                loc.first=cnt;
                loc.second=i;
            }

            
        }
        return loc.second;


    }
    void dijkstra(vector<Node> grid[],vector<int> &dist,vector<bool>& visited,int start,int N){
        dist[start]=0;
        for (int i = 0; i < N ; ++i)
        {
            int u=-1,min=INT_MAX;
            for (int j = 0; j < N; ++j)
            {
                if (!visited[j]&&min>dist[j])
                {
                    u=j;
                    min=dist[j];
                }
            }
            if (u==-1)
            {
                return;
            }
            visited[u]=true;
            //update
            for (int j = 0; j < grid[u].size(); ++j)
            {
                int v=grid[u][j].num;
                if (!visited[v]&&dist[v]>dist[u]+grid[u][j].weight)
                {
                    dist[v]=dist[u]+grid[u][j].weight;
                }
            }
        }

    }
};