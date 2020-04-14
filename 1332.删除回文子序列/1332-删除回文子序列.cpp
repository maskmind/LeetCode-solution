class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.length()==0)
        {
            return 0;
        }
        string str=s;
        reverse(s.begin(),s.end());
        if (str==s)
        {
            return 1;
        }else{
            return 2;
        }

    }
};