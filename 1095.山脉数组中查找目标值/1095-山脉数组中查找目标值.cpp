/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        if(mountainArr.get(peak)==target){
            return peak;
        }
        int res = binary_search(mountainArr, 0, peak-1, target);
        if(res!=-1){
            return res;
        }
        return binary_search(mountainArr, peak+1, mountainArr.length()-1, target, true);
    }

private:
    int findPeak(MountainArray &mountainArr){
        int len = mountainArr.length();
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int binary_search(MountainArray &mountainArr, int left, int right, int target, bool arrayReversed=false){          
        while(left <= right){
            int mid = left + (right-left)/2;
            int midValue = mountainArr.get(mid);
            if(midValue == target){
                return mid;
            }
            if(arrayReversed? midValue > target : midValue < target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return -1;
    }
};

