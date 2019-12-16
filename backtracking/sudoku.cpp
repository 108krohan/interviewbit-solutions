/*


Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'
You may assume that there will be only one unique solution.

A sudoku puzzle,

and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]

and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

S

*/

int c2n(char c){ //utility for character to number conversion
    if(c >='0' && c<='9') return c - '0';
    return -1;
}

bool isValid(vector<vector<char> > &A, int row, int col, int v){
    for(int i=0; i<9; i++) if(c2n(A[row][i]) == v) return false; //check in row
    for(int i=0; i<9; i++) if(c2n(A[i][col]) == v) return false; //check in col
    int rb = 3*(row/3), cb=3*(col/3);
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(c2n(A[rb+i][cb+j])==v) return false; //check in block
    return true;
}

bool found = false;

void solve(vector<vector<char> > &A, int row, int col){
    if(row==9){ //sudoku successfully filled
        found = true;
        return;
    }
    else if(A[row][col]=='.'){ //empty spot
        for(int i=1; i<=9; i++){
            if(isValid(A, row, col, i)){
                A[row][col] = i+'0';
                if(col==8) solve(A, row+1, 0); //if row has empty columns
                else solve(A, row, col+1);
            }
        }
        if(!found)   //backtrack if required
            A[row][col] = '.';
    }
    else if(!found){ //already filled
        if(col==8) solve(A, row+1, 0);
        else solve(A, row, col+1);
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    found = false;
    solve(A, 0, 0);
}

