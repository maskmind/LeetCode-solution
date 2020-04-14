class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (string str : emails)
        {
            size_t pos=str.find_first_of('@');
            string tmp="";
            for (auto i = 0; i < pos; ++i)
            {
                if (str[i]=='.')
                {
                    /* code */
                }else if (str[i]=='+')
                {
                    break;
                }else{
                    tmp+=str[i];
                }
            }
            tmp=tmp+str.substr(pos,str.length());
            s.insert(tmp);
        }
        return s.size();

    }
};