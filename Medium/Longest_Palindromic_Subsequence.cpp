#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(), dp[n][n];//dp(i, j)表示字串第i個字元到第j個字元間回文的最長長度
        memset(dp, 0, sizeof(dp));//不要用vector, 浪費記憶體也浪費時間
        //從每個字元左右擴展找回文
        for(int l=0; l<n; l++){
            for(int i=0; i<n-l; i++){
                int j = i+l;
                if(i == j)
                    dp[i][j] = 1;//只有一個字元時, 本身為一個回文, 長度為1
                else{
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;//若第i個字元和第j個字元相同就表示第i+1個字元到第j-1個字元間的回文左右在擴展一個字元
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};