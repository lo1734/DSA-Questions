The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

Code:

class Solution {
public:
    string convert(string s, int nr) {
        int n=s.length();
        if(nr==1) return s;
        bool flag=0;
        vector<string> rows(min(int(s.size()),nr));
        int crow=0;
        for(char c:s){
            if(crow<nr) rows[crow]+=c;
            if(crow==0||crow==nr-1) flag=!flag;
            crow+= flag?1:-1;
        }
        string res;
        for(auto r:rows){
            res+=r;
        }
        return res;
    }
};
