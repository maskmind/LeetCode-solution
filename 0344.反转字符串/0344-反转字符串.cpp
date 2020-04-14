class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0,ed=s.size()-1;
        char tmp;
        while(st<=ed){
            tmp=s[ed];
            s[ed]=s[st];
            s[st]=tmp;
            st++;
            ed--;
        }


    }
};