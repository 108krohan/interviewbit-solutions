/*

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/

#define ll long long int
int Solution::pow(int base, int expo, int m) {
    if(m == 1) 
        return 0;
    ll ans = 1, y = base % m;
    while(expo > 0){
        if(expo & 1)
         ans = ((ans) * y) % m;
        y = (y * y) % m;
        expo = expo >> 1;
    }
    if(ans < 0){
        ans = (m - abs(ans) % m);
        return ans;
    }
    return ans%m;
}
