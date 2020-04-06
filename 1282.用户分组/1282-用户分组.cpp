class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < groupSizes.size(); ++i)
        {
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            int vecSize=it->first;
            vector<int> user=it->second;
            vector<int>::iterator p=user.begin();
            while(p!=user.end()){
                vector<int> tmp(p,p+vecSize);
                res.push_back(tmp);
                p=p+vecSize;
            }
            
        }
        return res;

    }
};