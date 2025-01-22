// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

class Solution {
public:
    bool isSafe(int r,int c,int n,vector<string> &mat){
        int nr=r;
        int nc=c;
        while(r>=0&&c>=0){
            if(mat[r][c]=='Q') return 0;
            r--;
            c--;
        }
        r=nr;
        c=nc;
        while(r<n&&c>=0){
            if(mat[r][c]=='Q') return 0;
            r++;
            c--;
        }
        r=nr;
        c=nc;
        while(c>=0){
            if(mat[r][c]=='Q') return 0;
            c--;
        }
        return 1;
    }
    void fun(int j,int n,vector<string> &mat,vector<vector<string>> &res){
        if(j==n) {
            res.push_back(mat);
            return ;
        }
        for(int r=0;r<n;r++){
            if(isSafe(r,j,n,mat)){
                mat[r][j]='Q';
                fun(j+1,n,mat,res);
                mat[r][j]='.';
            }
        }        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> mat(n);
        string s(n,'.');
        if(n==1){
            res.push_back({"Q"});
            return res;
        }
        for(int i=0;i<n;i++){
            mat[i]=s;
        }
        fun(0,n,mat,res);
        return res;
    }
};
