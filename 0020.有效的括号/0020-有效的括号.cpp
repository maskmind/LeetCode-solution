class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length()%2)
        {
            return false;
        }
        if (s.length()==0)
        {
            return true;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            else if (s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if (st.empty())
                {
                    return false;
                }else{
                    char c=st.top();
                    if (s[i]==')'&&c!='(')
                    {
                        return false;
                    }else if (s[i]=='}'&&c!='{')
                    {
                        return false;
                    }else if (s[i]==']'&&c!='[')
                    {
                        return false;
                    }
                }
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
        
    }
};