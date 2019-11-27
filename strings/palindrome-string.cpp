/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int Solution::isPalindrome(string A) {
    int start = 0, end = A.size() - 1; 
    
    while(start < end) {
        while(start < end && !isalnum(A.at(start))) 
            start++;
        while(start < end && !isalnum(A.at(end)))
            end--;
        if(tolower(A.at(start)) != tolower(A.at(end)))
            return 0;
        start++;
        end--;
    }
    return 1;

}
