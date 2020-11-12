#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size(), cols = A[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i == 0){
                    dp[i][j] = A[i][j];
                }
                else{
                    dp[i][j] = A[i][j] + min(dp[i-1][max(0, j-1)], min(dp[i-1][j], dp[i-1][min(cols-1, j+1)]));
                }
            }
        }
        
        int mini = INT32_MAX;
        for(int i=0; i<cols; i++){
            mini = min(mini, dp[rows-1][i]);
        }
        
        return mini;
    }
};