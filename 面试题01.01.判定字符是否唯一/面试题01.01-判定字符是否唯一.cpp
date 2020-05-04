class Solution {
public:
    bool isUnique(string astr) {
        int cntChar[256]={0};
        for (int i = 0; i < astr.length(); ++i)
        {
            if (cntChar[astr[i]]==0)
            {
                cntChar[astr[i]]++;
            }else{
                return false;
            }
        }
        return true;

    }
};