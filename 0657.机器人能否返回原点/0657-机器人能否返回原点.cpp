class Solution {
public:
    bool judgeCircle(string moves) {
        int cntR=0,cntL=0,cntU=0,cntD=0;
        for (int i = 0; i < moves.length(); ++i)
        {
            if (moves[i]=='R')
            {
                cntR+=1;
            }
            else if (moves[i]=='L')
            {
                cntL+=1;
            }
            else if (moves[i]=='U')
            {
                cntU+=1;
            }
            else if (moves[i]=='D')
            {
                cntD+=1;
            }else{}
        }
        if ((cntR-cntL)==0&&(cntD-cntU)==0)
        {
            return true;
        }else{
            return false;
        }

    }
};