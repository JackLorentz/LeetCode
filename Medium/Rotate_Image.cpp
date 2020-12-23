#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /**
         * 解法1: 套順時針的旋轉公式, [[Cos(theta), Sin(theta)], [-Sin(theta), Cos(theta)]]
         * 但因為題目有要求不能額外宣告陣列, 所以此解法其實不合格(只是複習一下旋轉公式)
         * */
        /*int img[n][n];
        memset(img, 0, sizeof(img));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                img[j][-i+n-1] = matrix[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = img[i][j];
            }
        }*/
        /**
         * 解法2: 旋轉90度相當於轉置矩陣後再水平翻轉
        */
        if(n == 1)  return;
        for(int l=1; l<n; l++){
            for(int i=0; i<n-l; i++){
                int j = i+l;
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(&matrix[i][j], &matrix[i][n-j-1]);
            }
        }
    }
private:
    void swap(int *a, int *b){
        if(a != b){
            *a ^= *b;
            *b ^= *a;
            *a ^= *b;
        }
    }
};
