class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum=0;
        for (int left = 1,right=2; left<right;)
        {
            sum=(left+right)*(right-left+1)/2;
            if (sum<target)
            {
                right++;
            }
            else if (sum==target)
            {
                tmp.clear();
                for (int i = left; i <= right; ++i)
                {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                left++;
            }else{
                left++;
            }
        }
        return res;

    }
};