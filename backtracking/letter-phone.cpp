/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Make sure the returned strings are lexicographically sorted.

*/


void combo(string A, vector<string> &solution, string sofar, map<string, string> amap, int index)
{
    if(index == A.size()) {
        solution.push_back(sofar);
        return;
    }
    string options = amap.at(string(1, A.at(index)));
    for(int i = 0; i < options.size(); i++) 
    {
        combo(A, solution, sofar + options.at(i), amap, index + 1);
    }
}

vector<string> Solution::letterCombinations(string A) {
    map<string, string> amap;
    amap.insert({"0", "0"});
    amap.insert({"1", "1"});
    amap.insert({"2", "abc"});
    amap.insert({"3", "def"});
    amap.insert({"4", "ghi"});
    amap.insert({"5", "jkl"});
    amap.insert({"6", "mno"});
    amap.insert({"7", "pqrs"});
    amap.insert({"8", "tuv"});
    amap.insert({"9", "wxyz"});
    vector<string> solution;
    string sofar = "";
    // cout << amap.at(string(1, A.at(0))) << "something" << endl;
    combo(A, solution, sofar, amap, 0);
    return solution;
}
