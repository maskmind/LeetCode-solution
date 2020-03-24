int maxArea(int* height, int heightSize){
    if(height==NULL||heightSize<2){
        return -1;
    }
    int low=0;
    int high=heightSize-1;
    int result=0;
    while(low<high){
        int k=height[low]<height[high]? height[low]:height[high];
        result=result>=k*(high-low)?result:k*(high-low);
        if(height[low]<=height[high]){
            low++;
        }else{
            high--;
        }
    }
    return result;
}