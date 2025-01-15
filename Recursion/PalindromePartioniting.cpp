// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]


// Code:

class Solution {
public:
    bool isPal(string s){
        int l=0,r=s.length()-1;
        while(l<=r){
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    void fun(int idx,string &s,vector<string> temp,vector<vector<string>> &res){
        if(idx==s.length()){
            res.push_back(temp);
            return ;
        }
        for(int i=idx;i<s.length();i++){
            if(isPal(s.substr(idx,i-idx+1))){
                temp.push_back(s.substr(idx,i-idx+1));
                fun(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        fun(0,s,temp,res);
        return res;
    }
};
