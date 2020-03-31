class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n==0)return 0;
        string num=to_string(n);
        vector<char> v(num.begin(),num.end());
        int add_sum=0;
        int mup_sum=1;
        for (int i = 0; i < v.size(); ++i)
        {
            add_sum+=v[i]-'0';
            mup_sum=mup_sum*(v[i]-'0');
        }
        return mup_sum-add_sum;

    }
};