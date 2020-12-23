#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        //數學法(最快): 因為總共要向右走n-1次, 向下走m-1次, 所以就是排列組合問題 -> (m-1+n-1)!/(m-1)!(n-1)!
        int s = min(m, n);
        double num = 1.0, deno = 1.0;//分子是(m-1+n-1)!除掉(max(m, n)-1)!的結果
        //分母不得為0, 從1開始
        for(int i=1; i<=s-1; i++){
            num *= (m+n-1-i);
            deno *= i;
        }
        return int(num / deno);
        /*DP法: dp(i, j)表示走到這格有幾種走法, 第0行與第0列只有一種(來自上或左), 其餘的則是有兩種(來自上和左)所以為上和左兩格的加總
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];*/
    }
};