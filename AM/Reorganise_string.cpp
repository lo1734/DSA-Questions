Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Code:


class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        string res="";
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &e:mp){
            pq.push({e.second,e.first});
        }
        pair<int,char> prev={0,'#'};

        while(!pq.empty()){
            pair<int,char> c=pq.top();
            pq.pop();
            res+=c.second;

            if(prev.first>0) pq.push(prev);
            c.first--;
            prev=c;
        }
        if(res.size()!=s.size()) return "";
        return res;
    }
};
