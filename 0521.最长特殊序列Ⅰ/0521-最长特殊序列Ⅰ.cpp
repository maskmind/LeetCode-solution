class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)return -1;
        return a.length()>b.length()? a.length():b.length();
    }
};