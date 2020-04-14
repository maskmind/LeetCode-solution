class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomNumber=rooms.size();
        vector<bool> visited(roomNumber,false);
        visited[0]=true;
        dfs(rooms,visited,0);
        for (int i = 0; i < roomNumber; ++i)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;

    }
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int index){
        for (int i = 0; i < rooms[index].size(); ++i)
        {
            if (!visited[rooms[index][i]])
            {
                visited[rooms[index][i]]=true;
                dfs(rooms,visited,rooms[index][i]);
            }
        }
    }

};