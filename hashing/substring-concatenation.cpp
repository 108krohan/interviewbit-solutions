/*


You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

bool isvalid(string str, vector<string> B){
    int B_size = B.size();
    int ele_size = B[0].size();
    
    unordered_map<string, int> map1;
    
    for(int i =0; i<B_size; i++){
        if(map1.find(B[i]) == map1.end()) map1[B[i]] = 1;
        else map1[B[i]]++;
    }
    
    for(int i = 0; i<str.length(); i+=ele_size){
        string sub_string = str.substr(i, ele_size);
        if(map1.find(sub_string) != map1.end()){
            if(map1[sub_string] > 0)  map1[sub_string]--;
            else return false;
        }
        else return false;
    }
    return true;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> vec;
    int A_length = A.length();
    int B_size = B.size();
    int ele_size = B[0].size();
    int req_length = B_size * ele_size;
    for(int i = 0; i<A_length-req_length+1; i++){
        string sub = A.substr(i, req_length);
        if(isvalid(sub, B)) vec.push_back(i);
    }
    return vec;
    
}
