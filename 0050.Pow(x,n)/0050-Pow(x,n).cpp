class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        return N>=0? getResult(x,N):1.0/getResult(x,-N);
        
    }
    double getResult(double x,long long n){
        if (n==0)
        {
            return 1.0;
        }
        double res=getResult(x,n/2);
        return n%2==0? res*res:res*res*x;
    }
};