/*

Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.



Input Format

The only argument given is the integer array A.

Output Format

Return the area of largest rectangle in the histogram.

For Example

Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.

*/

int Solution::largestRectangleArea(vector<int> &htarr) {
    int i = 0;
    stack<int>stack;
    int maxarea = 0;
    htarr.push_back(0);
    while(i < htarr.size()){
        if(stack.empty()){
            stack.push(i);
            i++;
        }
        else{
            if(htarr[i] > htarr[stack.top()]){
                stack.push(i);
                i++;
            }
            else{
                int t = stack.top();
                stack.pop();
                int currarea;
                if(stack.empty()){
                    currarea = htarr[t]*(i);
                }
                else{
                    currarea = htarr[t]*(i-1-stack.top());
                }
                
                if(currarea > maxarea){
                    maxarea = currarea;
                }
            }
        }
    }
    
    // this needs to happen if don't push_back(0);
    // while(!stack.empty()){
    //     int t = stack.top();
    //     stack.pop();
        
    //     int currarea;
    //     if(stack.empty()){
    //         currarea = htarr[t]*(i);
    //     }
    //     else{
    //         currarea = htarr[t]*(i-1-stack.top());
    //     }
        
    //     if(currarea > maxarea){
    //         maxarea = currarea;
    //     }
    // }
    
    return maxarea;
    
}
