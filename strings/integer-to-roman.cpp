/*

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input Format

The only argument given is integer A.

Output Format

Return a string denoting roman numeral version of A.

Constraints

1 <= A <= 3999

For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"

*/

string Solution::intToRoman(int num) { 
    // 1000, 2000, 3000
    string M[] = {"", "M", "MM", "MMM"};
    // 100, 200, 300, .. 900
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    // 10, 20, ... 90
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    // 1, 2, ... 9
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
