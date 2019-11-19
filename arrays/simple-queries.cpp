/*

You are given an array A having N integers.

You have to perform the following steps in a given order.

    generate all subarrays of A.
    take the maximum element from each subarray of A and insert it into a new array G.
    replace every element of G with the product of their divisors mod 1e9 + 7.
    sort G in descending order
    perform Q queries

In each query, you are given an integer K, where you have to find the Kth element in G.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Input Format

The first argument given is an Array A, having N integers.
The second argument given is an Array B, where B[i] is the ith query.

Output Format

Return an Array X, where X[i] will have the answer for the ith query.

Constraints

1 <= N <= 1e5
1 <= A[i] <= 1e5
1 <= Q <= 1e5
1 <= k <= (N * (N + 1))/2 

For Example

Input:
    A = [1, 2, 4]
    B = [1, 2, 3, 4, 5, 6]
Output:
    X = [8, 8, 8, 2, 2, 1]
   
Explanation:
    subarrays of A	  maximum element
    ------------------------------------
    1. [1]							1
    2. [1, 2]						2
    3. [1, 2, 4]					4
    4. [2]							2
    5. [2, 4]						4
    6. [4]							4

	original
	G = [1, 2, 4, 2, 4, 4]
	
	after changing every element of G with product of their divisors
	G = [1, 2, 8, 2, 8, 8]
	
	after sorting G in descending order
	G = [8, 8, 8, 2, 2, 1]

*/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> triangle;
    if(A == 0) {
        return triangle;
    }
    triangle.push_back(vector<int>{1});
    if(A == 1) {
        return triangle;
    }
    triangle.push_back(vector<int>{1, 1});
    for(int row = 2; row < A; row++) {
        vector<int> row_vec;
        row_vec.push_back(1);
        
        vector<int> prev_row = triangle.at(row - 1);
        for(int prev_row_index = 1; prev_row_index < prev_row.size(); prev_row_index += 1) {
            row_vec.push_back(prev_row.at(prev_row_index) + prev_row.at(prev_row_index - 1));
        }
        
        row_vec.push_back(1);
        triangle.push_back(row_vec);
    }
    
    return triangle;
}
