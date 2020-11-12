#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int sum = 0;
        vector<int> dp(cols, 0);//用來判斷X軸方向的1是否連續
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j] == 1){
                    dp[j]++;
                    sum += dp[j];//計算Y軸方向矩陣(nx1)數量
                    //計算X軸方向矩陣(1xm, nxm)數量
                    int mini = dp[j];
                    int k = j-1;
                    //一直往左找直到遇到底或0為止, 假如大於0就加這列的最小值, 因為每往左一格就代表多些矩陣可組合, 包含與右邊或上面相連的矩陣 
                    while(k >= 0 && mat[i][k] > 0){
                        mini = min(mini, dp[k]);
                        sum += mini;
                        k--;
                    }
                }
                else{
                    dp[j] = 0;
                }
            }
        }
        
        return sum;
    }
};