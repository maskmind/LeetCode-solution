class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        int i = 0;
        for(auto v: intervals){
            m[v[0]] = i++;
        } 
        vector<int> ans;
        for(auto v: intervals){
            auto it = m.lower_bound(v[1]);
            if(it == m.end()) ans.emplace_back(-1);
            else ans.emplace_back((*it).second);
        }
        return ans;
    }
};

