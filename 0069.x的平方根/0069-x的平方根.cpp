class Solution {
public:
    int mySqrt(int x) {
        double low=0,high=x;
        double mid=(low+x)/2;

        while(high-low>0.00001){
            if (mid*mid>x)
            {
                high=mid;
                mid=(high+low)/2;
            }else if (mid*mid<x)
            {
                low=mid;
                mid=(high+low)/2;
            }else{
                low=mid;
                high=mid;
                break;
            }
            

        }
        return (int)high;
    }
};