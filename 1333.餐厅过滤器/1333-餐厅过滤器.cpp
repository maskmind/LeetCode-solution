
/*const cmp(const vector<int> &a,const vector<int> & b){
        if (a[1]!=b[1])
        {
            return a[1]>b[1];
        }else{
            return a[0]>b[0];
        }

    }*/
class Solution {
private:
    static bool cmp(const vector<int> &a,const vector<int> & b){
        if (a[1]!=b[1])
        {
            return a[1]>b[1];
        }else{
            return a[0]>b[0];
        }

    }
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> toSort;
        for(auto it:restaurants){
            //find veg
            if (veganFriendly)
            {
                if (it[2]&&it[3]<=maxPrice&&it[4]<=maxDistance)
                {
                    toSort.push_back(it);
                }
            }else{
                if (it[3]<=maxPrice&&it[4]<=maxDistance)
                {
                    toSort.push_back(it);
                }
            }
        }
        sort(toSort.begin(),toSort.end(),cmp);
        vector<int>rt;
        for (auto item:toSort)
        {
            rt.push_back(item[0]);
        }
        return rt;

    }
};