class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> res;
        int len=S.length();
        if (len==0)
        {
            return res;
        }
        vector<char> vec(S.begin(),S.end());    
        vector<bool> visited(len,false);
        vector<char> tmp(len,'0');
        generaP(0,res,visited,len,tmp,vec);
        return res;

    }
    void generaP(int index,vector<string>& res,vector<bool>& visited,int len,vector<char>& tmp,vector<char>& vec){
        if (index==len)
        {
            string str="";
            for (char c: tmp)
            {
                str=str+c;
            }
            res.push_back(str);
        }
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                tmp[index]=vec[i];
                visited[i]=true;
                generaP(index+1,res,visited,len,tmp,vec);
                visited[i]=false;
            }
        }
    }
};