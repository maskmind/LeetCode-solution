class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string str="";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i]!=' ')
            {
                str+=s[i];
            }else{
                if (str.length()==0)
                {
                    continue;
                }else{
                    vec.push_back(str);
                    str="";
                }
            }
        }
        if (str.length()!=0)
        {
            vec.push_back(str);
        }
        str="";
        for (vector<string>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i)
        {
            if (i!=vec.rend()-1)
            {
                str+=*i+' ';
            }else{
                str+=*i;
            }
        }
        return str;


    }
};