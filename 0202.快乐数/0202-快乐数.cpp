class Solution {
public:
    int getNext(int n){
        int ans=0;
        while(n){
            ans += (n%10)*(n%10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=getNext(slow);
            fast=getNext(fast);
            fast=getNext(fast);
        }while(slow!=fast);
        return slow==1;
        
    }
};