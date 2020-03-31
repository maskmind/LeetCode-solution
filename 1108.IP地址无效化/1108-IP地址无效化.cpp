class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        for (int i = 0; i < address.length(); ++i)
        {
            if (address[i]=='.')
            {
                str=str+"[.]";
            }else{
                str=str+address[i];
            }
        }
        return str;

    }
};