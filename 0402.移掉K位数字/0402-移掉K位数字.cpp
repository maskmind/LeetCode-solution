class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int deleteTime=0;
        for (int i = 0; i < num.length(); ++i)
        {
            while(!stk.empty()&&num[i]<stk.top()&&k){
                stk.pop();
                k--;
            }
            if (stk.empty() && num[i] == '0')continue;
            stk.push(num[i]);
        }
        string str="";
        while(!stk.empty()){
            if (k>0)
            {
                k--;
            }else if (k==0){
                str=stk.top()+str;
            }
            stk.pop();

        }
        return str.length()==0? "0":str;


    }
};