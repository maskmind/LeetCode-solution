class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        for(int num : nums2){
            while(!s.empty()&&num>s.top()){
                m[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        while(!s.empty()){
            m[s.top()]=-1;
            s.pop();
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i)
        {
            res.push_back(m[nums1[i]]);
        }
        return res;


    }
};