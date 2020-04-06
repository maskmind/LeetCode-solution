class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()<=1)
        {
            return 0;
        }
        int max_index=0;
        int max_height=0;
        for (int i = 0; i < int(height.size()); ++i)
        {
            if (max_height<height[i])
            {
                max_height=height[i];
                max_index=i;
            }
        }
        int sum=0;
        int tmp=height[0];//ÔÝ´æ×î´óÖµ
        for (int i = 0; i < max_index; ++i)
        {
            if (tmp<height[i])
            {
                tmp=height[i];
            }else{
                sum=sum+tmp - height[i];
            }
            
        }
        tmp=0;
        for (int i = height.size()-1; i >max_index; i--)
        {
            if (tmp<height[i])
            {
                tmp=height[i];
            }else{
                sum=sum+tmp - height[i];
            }
        }
        return sum;
    }
};