class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
        {
            return s;
        }
        int str_len=s.length();
        vector<string> v(min(numRows,str_len),"");
        bool Down=false;
        int index=0;
        for (char ch:s)
        {
            v[index]+=ch;
            if (index==0||index==numRows-1)
            {
                Down=!Down;
            }
            if (Down)
            {
                index++;
            }else{
                index--;
            }
        }
        string re="";
        for(string in:v){
            re=re+in;
        }
        return re;
    }
};