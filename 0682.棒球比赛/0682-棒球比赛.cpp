class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (int i = 0; i < ops.size(); ++i)
        {
            if (ops[i]=="+")
            {
                int s1=stk.top();stk.pop();
                int s2=stk.top();
                stk.push(s1);
                stk.push(s1+s2);
            }else if(ops[i]=="D"){
                stk.push(stk.top()*2);
            }else if(ops[i]=="C"){
                stk.pop();
            }else{
                stk.push(atoi(ops[i].c_str()));
            }
        }
        int res=0;
        while(!stk.empty())
        {
            res  += stk.top(); 
            stk.pop();
        }
        return res;

    }
};