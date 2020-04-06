class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> v;
    vector<vector<int>> permute(vector<int>& nums) {
        
        int len=nums.size();
        vector<bool> visited(len,false);
        tmp.resize(len,0);
        generateP(nums,visited,0,len);
        return v;
        

    }
    void generateP(vector<int>& nums,vector<bool>& visited,int index,int len){
        if (index==len)
        {
            v.push_back(tmp);
            return ;
        }
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                tmp[index]=nums[i];
                visited[i]=true;
                generateP(nums,visited,index+1,len);
                visited[i]=false;
            }
        }
    }
};