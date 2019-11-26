/*

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

*/

int Solution::firstMissingPositive(vector<int> &A) {
    vector<bool> dict(A.size()+1,false);
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0 && A[i]<dict.size()) dict[A[i]]=true;
    }
    
    if(A.size()==1 && A[0]!=1) return 1;
    else if(A.size()==1 && A[0]==1) return 2;
    int i=0;
    for(i=1;i<dict.size();i++)
    {
        if(dict[i]==false) return i;
    }
    return i;
}


/* o(1) space!!!!

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}

*/
