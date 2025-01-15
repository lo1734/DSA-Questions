// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// code:

class Solution {
public:
    void fun(int open,int close,int n,string temp,vector<string> &res){
        if(open==n&&close==n){
            res.push_back(temp);
            return ;
        }
        if(open<n) fun(open+1,close,n,temp+'(',res);
        if(open>close) fun(open,close+1,n,temp+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        fun(0,0,n,temp,res);
        return res;
    }
};
