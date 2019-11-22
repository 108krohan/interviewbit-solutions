/*

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 


*/

int Solution::titleToNumber(string A) {
    
    int result = 0;
    reverse(A.begin(), A.end());
    for(int i = 0; i < A.length(); i++) {
        result += pow(26, i) * (A.at(i) - 'A' + 1);
    }
    return result;
}
