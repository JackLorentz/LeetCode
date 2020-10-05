#include <iostream>
#include <set>
using namespace std;

// 不斷尋找新的上界(封閉)與下界(開放)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        /*map<char, int> dict;
        int max_len = 0, len = 0;
        for(int i=0; i<s.length(); i++){
            if(dict.find(s[i]) == dict.end()){
                dict.insert(pair<char, int>(s[i], i));
                len++;
            }
            else{
                if(len > max_len){
                    max_len = len;
                }
                i = dict[s[i]] + 1;
                dict.clear();
                dict.insert(pair<char, int>(s[i], i));
                len = 1;
            }
        }
        if(len > max_len)   max_len = len;*/
        int max_len = 0, i=0, j=0;
        set<char> dict;
        while(i<s.length() && j<s.length()){
            if(dict.find(s[j]) == dict.end()){
                dict.insert(s[j]);
                j++;
                max_len = max(max_len, j-i);
            }
            else{
                dict.erase(s[i]);
                i++;
            }
        }
        return max_len;
    }
};