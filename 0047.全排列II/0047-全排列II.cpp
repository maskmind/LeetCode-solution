class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> vis(nums.size(),false);
        sort(nums.begin(),nums.end());

        dfs(res,nums,0,cur,vis);
        return res;
        
    }
    void dfs(vector<vector<int>>&res,vector<int>& nums,int count,vector<int>& cur,vector<bool>& vis){
        if (count==nums.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) {
                continue;
            }
            if (!vis[i])
            {
                cur.push_back(nums[i]);
                vis[i]=true;
                dfs(res,nums,count+1,cur,vis);
                vis[i]=false;
                cur.pop_back();
            }
        }
    }
};