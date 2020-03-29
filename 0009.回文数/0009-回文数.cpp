class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s=to_string(x);
        vector<char> v(s.begin(),s.end());
        int i=0,j=v.size()-1;
        while(i<=j){
            if (v[i]==v[j])
            {
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};