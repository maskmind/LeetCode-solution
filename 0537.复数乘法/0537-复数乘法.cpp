class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string fa="",la="",fb="",lb="";
        bool change=false;
        for (int i = 0; i < a.length()-1; ++i)
        {
            if ((a[i]=='-'||a[i]<='9'&&a[i]>='0')&&!change)
            {
                fa+=a[i];
            }
            else if (a[i]=='+')
            {
                change=true;
            }
            else
            {
                la+=a[i];
            }
        }
        change=false;
        for (int i = 0; i < b.length()-1; ++i)
        {
            if ((b[i]=='-'||b[i]<='9'&&b[i]>='0')&&!change)
            {
                fb+=b[i];
            }
            else if (b[i]=='+')
            {
                change=true;
            }
            else
            {
                lb+=b[i];
            }
        }
        int fai=stoi(fa),lai=stoi(la),fbi=stoi(fb),lbi=stoi(lb);
        string re=to_string(fai*fbi-lbi*lai)+'+'+to_string(fai*lbi+lai*fbi)+'i';
        return re;
        

    }
};