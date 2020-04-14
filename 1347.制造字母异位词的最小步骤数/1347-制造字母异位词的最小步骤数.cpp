class Solution {
public:
    int minSteps(string s, string t) {
        int len=s.length();
        vector<int> vecs(26,0);
        vector<int> vect(26,0);
        for (int i = 0; i < len; ++i)
        {
            vecs[s[i]-'a']+=1;
        }
        for (int i = 0; i < len; ++i)
        {
            vect[t[i]-'a']+=1;
        }
        int steps=0;

        for (int i = 0; i < 26; ++i)
        {
            if (vecs[i]<vect[i])
            {
                steps+=vect[i]-vecs[i];
            }
        }
        return steps;
    }
};