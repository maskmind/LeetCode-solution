class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()<=1)
        {
            return 0;
        }
        if (nums.size()<=nums[0])
        {
            return 1;
        }
        int maxpos=0,step=0,end=0;
        //Ì°ÐÄËã·¨
        for (int i = 0; i < nums.size()-1; ++i)
        {
            maxpos=max(maxpos,i+nums[i]);
            if (i==end)
            {
                step++;
                end=maxpos;
            }
        }
        return step;

        
    }
};