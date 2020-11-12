#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        /**
         * 母音字串可能數計算: 假如長度為k, 可以由長度k-1字串推算, 尾巴是a有5種可能, e有4種以此類推
         * 橫向表示那5個母音各自的數量(0-4分別表示5-1)
         * 縱向第i項表示長度為i的母音字串由幾個5/4/3/2/1組成
         * */
        int dp[n][5];
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0 && j > 0){
                    dp[i][j] = 0;
                }
                else{
                    //類似帕斯卡三角形
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        int sum = 0;
        for(int i=0; i<5; i++){
            sum += (5-i)*dp[n-1][i];
        }
        return sum;
    }
};