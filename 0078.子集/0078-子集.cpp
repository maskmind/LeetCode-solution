class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        res.push_back({});
        for (int num: nums)
        {
            vector<vector<int>> tmp=res;
            for (vector<int> &arr : tmp)
            {
                arr.push_back(num);
                res.push_back(arr);
            }
        }
        
        return res;        
    }
};