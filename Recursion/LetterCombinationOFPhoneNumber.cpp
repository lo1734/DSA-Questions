Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

code:
 class Solution {
public:
    void fun(int idx,string digits,string mp[],string temp,vector<string> &res){
        if(idx==digits.size()){
            res.push_back(temp);
            return;
        }
        int val=digits[idx]-'0';
        string s=mp[val];
        for(int i=0;i<s.length();i++){
            temp.push_back(s[i]);
            fun(idx+1,digits,mp,temp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mp[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp="";
        vector<string> res;
        if(digits.size()==0) return res;
        fun(0,digits,mp,temp,res);
        return res;
    }
};
