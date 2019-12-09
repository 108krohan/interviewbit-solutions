/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Input Format

The only argument given is integer array A.

Output Format

Return the total water it is able to trap after raining..

For Example

Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1: <img src="http://i.imgur.com/0qkUFco.png">
    
    In this case, 6 units of rain water (blue section) are being trapped.

*/

int Solution::trap(const vector<int> &A) {
    stack<int> st; 
    int result = 0; 
    for(int i = 0; i < A.size();i++) {
        int element = A.at(i);
        while(!st.empty()&&element > A.at(st.top())) {
            int indice = st.top(); 
            st.pop();
            if(!st.empty()) {
                result += (i - 1 - st.top()) * (min(A.at(st.top()), element) - A.at(indice));
            }
        }
        st.push(i);
    }
    return result;
}
