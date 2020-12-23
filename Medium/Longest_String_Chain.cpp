#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        /**
         * 思路: 利用刪字元的方式看有哪字串屬於該字串的predecessor
         * max_str_len: 所有字串的最長長度
         * max_chain_len: word chain的最長長度
        */
        int n = words.size(), max_str_len = 0, max_chain_len = 1;
        map<int, vector<string>> len_map;//分類每種長度的字串
        map<string, int> dp;//以字串長度順序(小到大)來看, 該字串之前word chain的最長長度
        
        //由於同長度的字串彼此之間不會是互相的predecessor, 所以以長度來分類字串
        for(int i=0; i<n; i++){
            int len = words[i].length();
            len_map[len].push_back(words[i]);
            max_str_len = max(max_str_len, len);
        }
        //根據字串長度找word chain
        for(int i=1; i<=max_str_len; i++){
            map<int, vector<string>>::iterator it = len_map.find(i);
            //如果有該長度的字串
            if(it != len_map.end()){
                for(string s : len_map[i]){
                    map<int, vector<string>>::iterator it2 = len_map.find(i-1);
                    //如果這是最短字串, 該word chain為1
                    if(it2 == len_map.end())
                        dp[s] = 1;
                    else{
                        int cur_max_chain_len = 1, l = s.length();
                        //把每個字元都刪掉一次尋找predecessor
                        for(int j=0; j<l; j++){
                            string t = s;
                            t.erase(j, 1);
                            cur_max_chain_len = max(cur_max_chain_len, dp[t]+1);
                        }
                        dp[s] = cur_max_chain_len;
                        max_chain_len = max(max_chain_len, cur_max_chain_len);
                    }
                }
            }
        }
        return max_chain_len;
    }
};