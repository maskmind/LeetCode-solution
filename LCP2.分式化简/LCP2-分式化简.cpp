class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> v(2,0);
        if (cont.size()==1)
        {
            v[0]=cont[0];
            v[1]=1;
            return v;
        }
        int len=cont.size()-1;
        v[1]=cont[len];
        v[0]=1;
        for (int i = len-1; i >=0; i--)
        {
            v[0]=cont[i]*v[1]+v[0];
            if (i!=0)
            {
                int tmp=v[0];
                v[0]=v[1];
                v[1]=tmp;
            }
        }
        return v;
      
    }
};