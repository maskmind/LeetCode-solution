class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int len=INT_MAX;
        int idx1=-1,idx2=-1;
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i]==word1)
            {
                idx1=i;
            }else if (words[i]==word2)
            {
                idx2=i;
            }
            if (idx1!=-1&&idx2!=-1)
            {
                len=min(len,abs(idx1-idx2));   
            }
        }
        return len;

    }
};