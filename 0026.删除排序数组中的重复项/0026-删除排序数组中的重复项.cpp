class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
		if (len<=1)
		{
			return len;
		}
        int q=0,p=1;
		for (; p < len; p++)
		{
			if (nums[q]!=nums[p])
			{
                nums[q + 1] = nums[p];
				q++;
			}
		}
		return q + 1;
	}
};