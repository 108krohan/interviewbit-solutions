/*


Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/


void make_subsets(vector<int> A, vector<vector<int>> &solution, int index, vector<int> temp)
{
    solution.push_back(temp);
    
    for(int i = index; i < A.size(); i++) {
        temp.push_back(A.at(i)); 
        make_subsets(A, solution, i + 1, temp); 
        temp.pop_back(); 
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    sort(A.begin(), A.end());
    vector<vector<int>> solution;
    vector<int> temp;
    
    make_subsets(A, solution, 0, temp);
    return solution;
}
