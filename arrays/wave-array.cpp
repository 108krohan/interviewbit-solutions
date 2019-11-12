/*
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

    NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
    So, in example case, you will return [2, 1, 4, 3] 
*/

vector<int> Solution::wave(vector<int> &Vec) {
  
    // sort array
    sort(Vec.begin(), Vec.end());
    int N = Vec.size();
    
    // for every 0, 2, 4, 6, ...
    // swap (0, 1), (2, 3), and so on
    for(int i = 0; i < N - 1; i += 2) {
        swap(Vec[i], Vec[i + 1]);
    }
    return Vec;
}
