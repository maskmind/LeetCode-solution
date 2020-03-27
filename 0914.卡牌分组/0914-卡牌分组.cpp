class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        map<int, int>::const_iterator iteMap = m.begin();
	    for (int item : deck) {
            iteMap=m.find(item);
		    if (iteMap!=m.end())//zhaodao
		    {
			    m[item] = m[item] + 1;
		    }
		    else
		    {
			    m.insert(make_pair(item, 1));
		    }
	    }
	    int g = -1;
	   
	    for (iteMap=m.begin(); iteMap != m.end(); iteMap++) {
		    if (~g) g = gcd(g, iteMap->second);
		    else g = iteMap->second;
	    }
	    return g >= 2 ? true : false;
    }
   
};