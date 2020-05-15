class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> stringSet;
        set<string> rt;
        cout<<s.length();
        if (s.length()<10)return vector<string>{};
        //else if(s.length()==10)return vector<string>{s};
        for (int i = 0; i < s.length()-9; ++i)
        {
            string tmp=s.substr(i,10);
            if (stringSet.find(tmp)!=stringSet.end())
            {
               rt.insert(tmp);
            }else{
                stringSet.insert(tmp);
            }
            
        }
        return vector<string>(rt.begin(),rt.end());

    }
};