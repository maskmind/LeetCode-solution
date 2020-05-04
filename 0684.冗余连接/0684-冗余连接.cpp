class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(100000,-1);
        for (int i = 0; i < root.size(); ++i)
        {
            root[i]=i;
        }
        for(auto ed: edges){
            int xfather=findfather(ed[0],root);
            int yfather=findfather(ed[1],root);
            if (xfather!=yfather)
            {
                root[xfather]=yfather;
            }else{
                return ed;
            }

        }
        return vector<int>{0,0};


    }
    int findfather(int x,vector<int> &root){
        while(x!=root[x]){
            x=root[x];
        }
        return x;
    }
};