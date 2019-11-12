/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 

You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Input :

Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.

Output :

Return an Integer, i.e minimum number of steps.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2

It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    long long int solution = 0; 
    
    for(int point = 0; point + 1 < B.size(); point++) // + 1 because comparing with next
    {
        // this point
        int x = A.at(point);
        int y = B.at(point); 
        
        // next point
        int x_plus = A.at(point + 1); 
        int y_plus = B.at(point + 1); 
        
        // max of modulus of whichever is bigger different b/w co-ordinates
        solution += max(abs(x - x_plus), abs(y - y_plus)); 
    }
    return solution;
}
