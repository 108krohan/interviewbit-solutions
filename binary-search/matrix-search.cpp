/*

Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first argument given is the integer matrix A.
The second argument given is the integer B.

Output Format

Return 1 if B is present in A, else return 0.

Constraints

1 <= N, M <= 1000
1 <= A[i][j], B <= 10^6

For Example

Input 1:
    A = 
    [ [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]  ]
    B = 3
Output 1:
    1

Input 2:
    A = [   [5, 17, 100, 111]
            [119, 120,  127,   131]    ]
    B = 3
Output 2:
    0

*/

int BinarySearch(vector<int> &A, int i, int j, int B)
{
    if (i <= j)
    {
        int mid = (i + j) / 2;
        if (A[mid] == B)
        {
            return mid;
        }
        if (A[mid] < B)
            return BinarySearch(A, mid + 1, j, B);
        else
            return BinarySearch(A, i, mid - 1, B);
    }
    return -1;
}
int BinarySearch1(vector<vector<int> > &A, int i, int j, int B)
{
    if (i <= j)
    {
        int mid = (i + j) / 2;
        if (A[mid][0] == B)
        {
            return mid;
        }
        if (A[mid][0] < B)
            return BinarySearch1(A, mid + 1, j, B);
        else
            return BinarySearch1(A, i, mid - 1, B);
    }
    return j;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B)
{
    int row = BinarySearch1(A, 0, A.size() - 1, B);
    if (row == -1) return 0;
    if (A[row][0] == B)
        return 1;

    int col = BinarySearch(A[row], 0, A[row].size() - 1, B);
    if (col == -1)
        return 0;
    return 1;
}
