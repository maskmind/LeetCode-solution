class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int idxPush=0,idxPop=0;
        while(idxPush<pushed.size()){
            s.push(pushed[idxPush]);
            idxPush++;
            while(!s.empty()&&idxPop<popped.size()&&s.top()==popped[idxPop]){
                s.pop();
                idxPop++;
            }
        }
        return idxPop==popped.size();

    }
};