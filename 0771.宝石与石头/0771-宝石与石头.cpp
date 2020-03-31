class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool arr[256];
        for (int i = 0; i < 256; ++i)
        {
            arr[i]=false;
        }
        for (int i = 0; i < J.length(); ++i)
        {
            arr[J[i]]=true;
        }
        int cnt=0;
        for (int i = 0; i < S.length(); ++i)
        {
            if (arr[S[i]])
            {
                cnt++;
            }
        }
        return cnt;

    }
};