/*

Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/

int Solution::reverse(int A) {
    long int sol = 0;
    while(A != 0){
        sol = sol*10 + (A%10);    
        A = A/10;
    }
    if(sol > INT_MAX || sol < INT_MIN){
        return 0;
    }
    return (int)sol;
}
