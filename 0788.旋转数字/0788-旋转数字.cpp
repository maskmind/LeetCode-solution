class Solution {
public:
    int rotatedDigits(int N) {
        int cnt=0;
        for (int i = 1; i < N+1; ++i)
        {
            int tmp=i;
            bool flag=false;
            while(tmp){
                int t=tmp%10;
                if (t==3||t==4||t==7)
                {
                    flag=false;
                    break;
                }
                if (t==2||t==5||t==6||t==9)
                {
                    flag=true;
                }
                tmp/=10;
            }
            if (tmp==0&&flag)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};