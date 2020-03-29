class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0)return 0;
        vector<char> v(str.begin(),str.end());
        
        v.push_back(' ');
        int len=v.size();
        int st=0,ed=0;
        // first not null
        while(st<len){
            if (v[st]!=' ')
            {
                break;
            }
            st++;
        }
        if(st==v.size())return 0;
        //<0biaozhi
        bool flag=false;
        if (v[st]=='+'&&st<v.size())
        {
            st++;
            ed=st;
        }
        else if (v[st]=='-'&&st<v.size())
        {
            st++;
            ed=st;
            flag=true;
        }
        else if (v[st]>='0'&&v[st]<='9'&&st<v.size())
        {
            ed=st;
        }else{
            return 0;
        }

        while(v[ed]>='0'&&v[ed]<='9'&&ed<v.size()){
            ed++;
        }
        long long res=0;
        for (int i = st; i <ed; ++i)
        {
            if (flag)
            {
                res=res*10-(v[i]-'0');
                if (res<INT_MIN)
                {
                    return INT_MIN;
                }
            }else{
                res=res*10+v[i]-'0';
                if (res>INT_MAX)
                {
                    return INT_MAX;
                }
            }
        }
        return res;
    }
};