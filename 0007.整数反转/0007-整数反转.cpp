class Solution {
public:
    int reverse(int x) {
        string str=to_string(x);
        vector<char> v(str.begin(), str.end());
        int st=0,ed=v.size()-1;
        while(st<ed){
            if (st==0&&v[st]=='-')
            {
                st++;
            }else{
                char tmp=v[ed];
                v[ed]=v[st];
                v[st]=tmp;
                st++;
                ed--;
            }
        }
        int len;
        long long res=0;
        if (v[0]=='-')
        {
           for (int i = 1; i < v.size(); ++i)
           {
               res=res*10+(v[i]-'0');
               if(res>INT_MAX&&i<v.size())return 0;
           }
           res=-res;
        }else{
            for (int i = 0; i <v.size() ; ++i)
            {
                res=res*10+(v[i]-'0');
                if(res>INT_MAX&&i<v.size())return 0;
            }
        }
        return res;
    }
};