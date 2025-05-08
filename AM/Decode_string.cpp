Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Code:

class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        stack<int> num_st;
        stack<string> str_st;
        string res="";
        string num="";
        for(auto c:s){
            if(isdigit(c)){
                num+=c;
            }
            else if(c=='['){
                num_st.push(stoi(num));
                num="";
                str_st.push("[");
            }
            else if(c==']'){
                string temp="";
                while(str_st.top()!="["){
                    temp+=str_st.top();
                    str_st.pop();
                }
                str_st.pop();
                int k=num_st.top();
                num_st.pop();
                string s="";
                for(int i=0;i<k;i++){
                    s+=temp;
                }
                str_st.push(s);
            }
            else str_st.push(string(1,c));
        }
        while(!str_st.empty()){

            res+=str_st.top();
            str_st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
