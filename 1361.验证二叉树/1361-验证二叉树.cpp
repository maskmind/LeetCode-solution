class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> input(n,0);
        for (int i = 0; i < n; ++i)
        {
            if (leftChild[i]!=-1)
            {
                input[leftChild[i]]++;
            }
            if (rightChild[i]!=-1)
            {
                input[rightChild[i]]++;
            }
        }
        //find root
        int root=-1;
        for (int i = 0; i < n; ++i)
        {
            if (input[i]==0)
            {
                root=i;
                break;
            }
        }
        if(root==-1)return false;
        vector<int> visited(n,0);
        stack<int> s;
        s.push(root);
        visited[root]=1;
        while(!s.empty()){
            int p=s.top();s.pop();
            if(leftChild[p]!=-1){
                if (visited[leftChild[p]]>0)
                {
                    return false;
                }
                visited[leftChild[p]]+=1;
                s.push(leftChild[p]);
            }
            if(rightChild[p]!=-1){
                if (visited[rightChild[p]]>0)
                {
                    return false;
                }
                visited[rightChild[p]]+=1;
                s.push(rightChild[p]);
            }
        }
        int cnt=0;
        for (int i = 0; i < n; ++i)
        {
            if (visited[i]==1)
            {
                cnt++;
            }
        }
        return cnt==n?true:false;
    }
};