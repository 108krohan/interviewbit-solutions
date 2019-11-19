/*

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

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
