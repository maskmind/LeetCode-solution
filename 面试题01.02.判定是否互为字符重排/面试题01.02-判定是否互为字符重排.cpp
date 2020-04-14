class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length()!=s2.length())
        {
            return false;
        }
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for (int i = 0; i < s1.length(); ++i)
        {
            vec1[s1[i]-'a']+=1;
        }
        for (int i = 0; i < s2.length(); ++i)
        {
            vec2[s2[i]-'a']+=1;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (vec1[i]!=vec2[i])
            {
                return false;
            }
        }
        return true;

    }
};