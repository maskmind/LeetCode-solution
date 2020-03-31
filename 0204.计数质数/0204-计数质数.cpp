class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int> v(n,1);
        v[0]=0,v[1]=0;
        for (int i = 2; i < n; ++i)
        {
            if (v[i]==1)
            {
                for (int j = i+i; j < n; j+=i)
                {
                    v[j]=0;
                }
            }
        }
        int cnt=0;
        for (int item:v)
        {
            if (item)
            {
                cnt++;
            }
        }
        return cnt;

    }
    bool isPrime(int n){
        if(n<=1)return false;
        if(n==2)return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};