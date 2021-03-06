/*

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

*/

int Solution::trailingZeroes(int A) {
    int result = 0; 
    
    for(int i = 5; i <= A; i *= 5) {
        result += A / i;
    }
    
    return result;
}
