Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

code:
class Solution {
public:
    bool isValid(int i,int j,char c,vector<vector<char>> &mat){
        for(int k=0;k<9;k++){
            if(mat[i][k]==c) return 0;
            if(mat[k][j]==c) return 0;
            if(mat[3*(i/3)+k/3][3*(j/3)+k%3]==c) return 0;
        }
        return 1;
    }
    bool fun(vector<vector<char>> &mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                       if(isValid(i,j,c,mat)){
                            mat[i][j]=c;
                            if(fun(mat)){
                                return 1;
                            }
                            else mat[i][j]='.';
                       }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& mat) {
        fun(mat);
    }
};
