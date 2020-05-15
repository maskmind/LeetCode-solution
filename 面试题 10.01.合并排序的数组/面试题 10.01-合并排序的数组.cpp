class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int len=m+n-1;
        int pa=m-1,pb=n-1;
        int curval;
        while(pa>=0||pb>=0){
            if (pa==-1)
            {
                curval=B[pb];
                pb--;
            }
            else if (pb==-1)
            {
                curval=A[pa];
                pa--;
            }
            else if (A[pa]>=B[pb])
            {
                curval=A[pa];
                pa--;
            }else{
                curval=B[pb];
                pb--;
            }
            A[len]=curval;
            len--;

        }
        

    }
};