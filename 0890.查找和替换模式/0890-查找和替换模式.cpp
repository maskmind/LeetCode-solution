class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;

        for (string str:words)
        {
            if (checkPattern(str,pattern)&&checkPattern(pattern,str))
            {
                ret.push_back(str);
            }
        }
        return ret;

    }
    bool checkPattern(string word,string pattern){
        if (word.length()!=pattern.length())
        {
            return false;
        }
        vector<int> v(26,-1);
        for (int i = 0; i < word.size(); ++i)
        {
            if (v[pattern[i]-'a']==-1)
            {
                v[pattern[i]-'a']=word[i]-'a';
            }
            else if (v[pattern[i]-'a']!=word[i]-'a')
            {
                return false;
            }
        }
        return true;

    }
};