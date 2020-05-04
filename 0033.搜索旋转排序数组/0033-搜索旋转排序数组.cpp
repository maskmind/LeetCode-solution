class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        if (right<0)
        {
            return -1;
        }
        if (right==0)
        {
            return target==nums[0]? 0:-1;
        }
        while(left<=right){
            int mid=(left+right)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            if (nums[0] <= nums[mid])
            {
                if (nums[0]<=target&&target<nums[mid])
                {
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if (nums[mid]<target &&target<=nums[nums.size()-1])
                {
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
        
    }
};