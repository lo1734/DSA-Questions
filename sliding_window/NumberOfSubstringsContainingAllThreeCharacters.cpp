Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1

Code:

class Solution {
public:
    int fun(string &s,int k){
        int n=s.length();
        unordered_map<char,int> mp;
        int l=0,r=0;
        int res=0;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
    int numberOfSubstrings(string s) {
        return fun(s,3)-fun(s,2);
    }
};
