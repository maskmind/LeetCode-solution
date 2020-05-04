class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)return 0;
        if(n == 1)return 1;
        return (n % 3 == 0) && isPowerOfThree(n / 3);



    }
};