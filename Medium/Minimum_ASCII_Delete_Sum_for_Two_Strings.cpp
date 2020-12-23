#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));//dp(i, j)表示字串s1[:i]和s2[:j]之間共同子字串最大成本(ASCII和)
        //用LCS方式尋找共同子字串最大成本
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + (int)s1[i-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        //全部扣掉共同子字串最大成本就是刪除最低成本
        int sum1=0, sum2=0;
        for(int i=0; i<n1; i++){
            sum1 += (int)s1[i];
        }
        for(int i=0; i<n2; i++){
            sum2 += (int)s2[i];
        }
        return sum1 + sum2 - 2*dp[n1][n2];
    }
};