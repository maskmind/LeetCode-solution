class Solution {
public:
    int countSubstrings(string s) {
        int rt=0;
        for (int i = 0; i < s.length(); ++i)
        {
            rt += getSubstr(s,i,i);
            rt += getSubstr(s,i,i+1);
        }
        return rt;

    }
    int getSubstr(string s ,int start,int end){
        int cnt=0;
        while(start>=0&&end<s.length()){
            if (s[start]==s[end])
            {
                cnt++;
                start--;
                end++;
            }else{
                break;
            }
        }
        return cnt;
    }
};