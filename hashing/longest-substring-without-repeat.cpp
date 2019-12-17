/*

Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.


*/

int Solution::lengthOfLongestSubstring(string A) {
    int n= A.size();
    if(n<=1) return n;
     int ans=0, j=-1, i=0;
    unordered_map<char, int> mp;
    for(i=0; i<A.size(); i++){
        if(mp.find(A[i]) != mp.end())
            j = max(mp[A[i]], j);
            ans = max(i-j, ans);
            mp[A[i]] = i;
    }
    return ans;
}

