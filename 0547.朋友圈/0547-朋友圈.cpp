class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> root ;
        for (int i = 0; i <M.size(); i++) {
		    root.push_back(i);
	    }
	    for (int i = 0; i < M.size(); i++) {
		    for (int j = 0; j <= i; j++) {
			    if (i != j && M[i][j] == 1)
				    Union(root, i, j);
		    }
	    }
        int cnt = 0;
	    for (int i = 0; i <root.size(); i++) {
		    if (root[i] == i) {
			    cnt++;
		    }
        }
       return cnt;
    }

 int find(vector<int> root,int x) {
	 while (root[x]!=x)
	 {
		 x = root[x];
	 }
	 return x;
 }
void Union(vector<int> &v, int x, int y) {
	 int xset = find(v, x);
	 int yset = find(v, y);
	 if (xset != yset) {
		 v[xset] = yset;
	 }		 
 }
};