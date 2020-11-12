#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0, n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));//dp(i,j)代表字串第i個字元到第j個字元是否回文
        //從對角線開始往上三角形一層層運算是否回文
        for(int l=0; l<n; l++){
            for(int i=0; i<n-l; i++){
                int j = i+l;
                if(j < n){
                    //單字必回文
                    if(i == j){
                        dp[i][j] = 1;
                    }
                    //假若第i個字元和第j個字元相同, 若只有兩個字或者是左右各少一個字元還是回文則第i個字元到第j個字元是回文
                    else if(s[i] == s[j]){
                        if(dp[i+1][j-1] == 1 || abs(i-j) == 1){
                            dp[i][j] = 1;
                        }
                    }
                    sum += dp[i][j];
                }
            }
        }
        
        return sum;
    }
};