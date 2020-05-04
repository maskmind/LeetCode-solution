class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int rt;
        rt=dp[0]=nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);

        }
        for(auto it=dp.begin();it!=dp.end();it++){
            rt=max(rt,*it);

        }
        return rt;
        
    }
};