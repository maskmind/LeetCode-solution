class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len=T.size();
        vector<int> res(len,0);
        stack<int> s;
        for (int i = 0; i < T.size(); ++i)
        {
            while(!s.empty()&&T[i]>T[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;

    }
};