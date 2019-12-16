/*

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

    NOTE

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.

*/

void permutation(vector<int> &A, int st, vector<vector<int> > &v)
{
    if(st >= A.size())
    {
        v.push_back(A);
        return;
    }
    for(auto i=st; i<A.size(); i++)
    {
        swap(A[st], A[i]);
        permutation(A, st+1, v);
        swap(A[st], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int> > v;
    
    permutation(A, 0, v);
    
    return v;
}
