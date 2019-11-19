/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

int Solution::solve(vector<int> &A) {
    int n = A.size(), ans = -1, i = 0;
    
    sort(A.begin(), A.end());
    
    while(i < n){
        while(i+1 < n && A[i] == A[i+1]){
            i++;
        }
        
        if(n - (i+1) == A[i]){
            ans = 1;
            break;
        }
        
        i++;
    }
    
    return ans;
}
