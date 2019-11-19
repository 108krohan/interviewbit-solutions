/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

    NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
    For example, for this problem, following are some good questions to ask :

        Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?

        A : For the purpose of this question, YES
        Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
        A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

Custom cases: 

198
199
999
*/

vector<int> Solution::plusOne(vector<int> &A) {
    
    reverse(A.begin(), A.end());
    
    int carry = 1;
    
    for(int index = 0; index < A.size(); index++) {
        int new_value = A.at(index) + carry;
        if(new_value == 10) {
            A.at(index) = 0;
            carry = 1;
        }
        else {
            A.at(index) = new_value;
            carry = 0;
        }
    }
    if(carry == 1) {
        A.push_back(1);
    }
    
    reverse(A.begin(), A.end());
    // for(auto i : A) {
    //     cout << i << " ";
    // }
    
    int start_from = 0;
    while(A.at(start_from) == 0) {
        start_from += 1;
    }
    
    return vector<int>(A.begin() + start_from, A.end());
}
