/*

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

*/

// the idea here is quite simple: 
// xor of a number with itself makes it 0.
// so we take XOR of all guys, and take XOR of all numbers from 1 to n
// so the number that repeats would come out thrice. 

// but won't the number that never comes come out once? 
// i have left this unfigured out, let me know if you do

int Solution::repeatedNumber(const vector<int> &A) {
    int i,xor1=0;
    for(i=1;i<A.size();i++)
    {
        xor1^=A[i];
        xor1^=i;
    }
    xor1^=A[0];

    return xor1;
}
