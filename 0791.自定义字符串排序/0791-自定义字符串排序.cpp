class Solution {
public:
    string customSortString(string S, string T) {
        map<char, char> m;
        for (int i = 0; i < S.length(); ++i)
        {
            m[S[i]]='0'+i;
        }
        string res="";
        string sortS="";
        for (int i = 0; i < T.length(); ++i)
        {
            if (m.find(T[i])!=m.end())
            {
                sortS+=m[T[i]];
            }else{
                res+=T[i];
            }
        }
        sort(sortS.begin(),sortS.end());
        for (int i = 0; i < sortS.size(); ++i)
        {
            for(map<char,char>::iterator it = m.begin();it!=m.end();it++) 
            {
                if(it->second==sortS[i])
                    res+=it->first;
                    
            }            
        }
        return res;

    }
};