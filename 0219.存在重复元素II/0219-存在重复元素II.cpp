class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> M;       //存储最近下标
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>::iterator iter=M.find(nums[i]);
            if(iter==M.end())
                M[nums[i]]=i;      
            else{
                if(i-(iter->second)<=k)
                    return 1;
                iter->second=i;
            }
        }
        return 0;
    }
};


