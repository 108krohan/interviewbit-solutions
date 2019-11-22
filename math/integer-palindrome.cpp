/*



Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False


*/

int Solution::isPalindrome(int A) {
    long long int B=0,s=A;
    if(A<0)
        return false;
    while(s>0)
    {
        B=B*10+s%10;
        s=s/10;
    }
    if(A!=B)
        return false;
    return true;
}
