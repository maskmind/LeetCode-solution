class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s==""||n==0)return s;
        string str1=s.substr(0,n);
        string str2=s.substr(n);
        return str2+str1;

    }
};