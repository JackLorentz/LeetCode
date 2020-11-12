#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        /**
         * 動態規劃首先要確定的是要先找到固定起始值去推算
         * 由於當2*M比剩下的石頭堆數多時即可全拿, 因此這題要從尾巴去推算
        */
        int n = piles.size();
        int remain[n];//第i項表示第i堆石頭到第n推的石頭總數, 也是剩下的石頭數
        vector<vector<int>> dp(n, vector<int>(n, 0));//二維陣列: (i, M)表示剩[i:]堆石頭時可拿M堆石頭時的最大擁有石頭數
        
        remain[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--){
            remain[i] = piles[i] + remain[i+1];
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+2*j >= n){
                    dp[i][j] = remain[i];
                }
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                /**
                 * 每次可拿1~2*M堆石頭, 因為Alex從第i個開始拿了x個, 所以Lee從i+x開始拿, 
                 * 並且依據遊戲規則max(j, M)去更新M, 所以換Lee拿石頭會依據(i+x, max(j,x))狀況拿
                */
                for(int x=1; x<=2*j && i+x<n; x++){
                    dp[i][j] = max(dp[i][j], remain[i] - dp[i+x][max(j, x)]);
                }
            }
        }
        
        return dp[0][1];//遊戲剛開始時:石頭未拿且M=1
    }
};