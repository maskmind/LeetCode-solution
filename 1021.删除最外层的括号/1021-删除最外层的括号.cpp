class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> stk;
        string res="";
        for (int i = 0; i < S.length(); ++i)
        {
            
            if (S[i]==')')
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                res+=S[i];
            }
            if (S[i]=='(')
            {
                stk.push(S[i]);
            }
            
        }
        return res;


    }
};