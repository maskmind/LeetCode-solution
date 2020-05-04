class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int last=A[0];
        int flag1=false,flag2=false;
        for (int i = 0; i < A.size(); ++i)
        {
            //二者仅有1个为true
            if (last<A[i])
            {
                last=A[i];
                flag1=true;
            }
            else if (last==A[i])
            {
                
            }
            else{
                last=A[i];
                flag2=true;
            }
        }
        if (flag1&&flag2)
        {
            return false;
        }else{
            return true;
        }

    }
};