Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0;
        int len=0,res=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                if(mp.find(s[l])!=mp.end()){
                    mp[s[l]]--;
                    l++;
                }
            }
            len=r-l+1;
            res=max(res,len);
            r++;
        }
        return res;
    }
};
