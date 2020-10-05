// Brute-force
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        vector<vector<int>> result(rows, vector<int>(cols, 0));//二維陣列初始化
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int sum = 0;
                for(int x=i-K; x<=i+K; x++){
                    for(int y=j-K; y<=j+K; y++){
                        if(x >= 0 && x < rows && y >= 0 && y < cols){
                            sum += mat[x][y];
                        }
                    }
                }
                result[i][j] = sum;
            }
        }
        return result;
    }
};
/**
 * DP
 * 思路: https://leetcode.jp/leetcode-1314-matrix-block-sum-%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF%E5%88%86%E6%9E%90/
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        vector<vector<int>> tmp(rows, vector<int>(cols, 0));
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            int sum = 0;
            for(int j=0; j<cols; j++){
                sum += mat[i][j];
                if(i == 0){
                    tmp[i][j] = sum;
                }
                else{
                    tmp[i][j] = sum + tmp[i-1][j];
                }
            }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                //找出總和範圍的4個座標
                int x1 = max(i-K, 0);
                int y1 = max(j-K, 0);
                int x2 = min(i+K, rows-1);
                int y2 = min(j+K, cols-1);
                if(x1 > 0 && y1 > 0){
                    result[i][j] = tmp[x2][y2] - tmp[x2][y1-1] - tmp[x1-1][y2] + tmp[x1-1][y1-1];
                }
                else if(x1 > 0 && y1 == 0){
                    result[i][j] = tmp[x2][y2] - tmp[x1-1][y2];
                }
                else if(x1 == 0 && y1 > 0){
                    result[i][j] = tmp[x2][y2] - tmp[x2][y1-1];
                }
                else{
                    result[i][j] = tmp[x2][y2];
                }
            }
        }
        return result;
    }
};