class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> word_set(words.begin(), words.end());
        for (int i = 0; i <words.size(); ++i)
        {
            for (int j = 1; j < words[i].length(); ++j)
            {
                word_set.erase(words[i].substr(j));
            }
        }
        int cnt=0;
        for(string str:word_set){
            cnt+=str.length()+1;
        }
        return cnt;

    }
};