/*

You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    int e1=INT_MAX,e2=INT_MAX,c1=0,c2=0;
    for(int val:A){
        if(val==e1&&c1>0){
            c1++;
        }else if(val==e2&&c2>0){
            c2++;
        }else if(c1==0){
            e1=val;
            c1++;
        }else if(c2==0){
            e2=val;
            c2++;
        }else{
            c1--;
            c2--;
        }
    }
    if(c1==0&&c2==0)return -1;
    c1=0;c2=0;
    for(int val:A){
        if(val==e1)c1++;
        if(val==e2)c2++;
        if(c1>A.size()/3)return e1;
        if(c2>A.size()/3)return e2;
    }
    return -1;
}

