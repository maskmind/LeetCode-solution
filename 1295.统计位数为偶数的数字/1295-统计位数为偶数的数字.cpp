class Solution {
public:
    int findNumbers(vector<int>& nums) {
        if (nums.size()==0)
        {
            return 0;
        }
        int cnt=0;
        for(int item:nums)
        {
            string str=to_string(item);
            if (str.length()%2==0)
            {
                cnt++;
            }

        }
        return cnt;
    }
};