/*

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

    Note: Each word is guaranteed not to exceed L in length. 

*/

string makeLine(vector<string> &list, int l, int start, int end){
    int len= 0;
    for (int i=start;i<=end; i++) len+= list[i].size();
    if (end==start){
        string ans= list[start];
        while (ans.size() < l) ans+=' ';
        return ans;
    }
    int a= (l-len)/(end-start);
    int b = (l-len)%(end-start);
    string ans="";
    ans+= list[start];
    for (int i=start+1; i<=end; i++){
        for (int j=0; j<a; j++) ans += ' ';
        if (i-(start+1)<b) ans+= ' ';
        ans+=list[i];
    }
    return ans;
}

string makeLastLine(vector<string> &list, int l, int start, int end){
    string ans= list[start];
    for (int i= start+1; i<=end; i++){
        ans+= ' ' + list[i]; 
    }
    while (ans.size()<l) ans+=' ';
    return ans;
}

vector<string> Solution::fullJustify(vector<string> &list, int l) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ans;
    int n= list.size();
    int i=0;
    int start=0;
    int prev=0;
    while (i < n){
        int l1= list[i].size();
        if ((i==start?0:1) + l1 + prev> l){
            ans.push_back(makeLine(list, l,start, i-1));
            start=i;
            prev=l1;
        }
        else prev+= l1+ ((i==start)?0:1);
        i++;
    }
    if (start!=n){
        ans.push_back(makeLastLine(list, l,start, n-1));
    }
    return ans;
}

