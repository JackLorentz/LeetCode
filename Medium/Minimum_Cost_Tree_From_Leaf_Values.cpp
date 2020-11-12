#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int s[n][n], m[n][n];//s代表i到j所構成BT的最小成本, m代表i到j所構成BT的最大葉子值
        //初始化: 對角線代表葉子
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    s[i][j] = arr[i];
                    m[i][j] = arr[i];
                }
                else{
                    s[i][j] = 0;
                    m[i][j] = 0;
                }
            }
        }
        //從葉子(對角線)開始往上計算
        for(int l=1; l<n; l++){
            for(int i=0; i<n-1; i++){
                int j = i+l;
                if(j < n){
                    m[i][j] = max(m[i+1][j], m[i][j-1]);
                    if(l == 1){
                        s[i][j] = s[i+1][j]*s[i][j-1];
                    }
                    else{
                        s[i][j] = INT32_MAX;
                        //i到j所有可能子樹構成計算: (i,i)(i+1,j)...(i,k)(k+1,j)...(i,j-1)(j,j), k=i...j-1
                        for(int k=i; k<j; k++){
                            if(i == k){
                                s[i][j] = min(s[i][j], s[k+1][j]+m[i][k]*m[k+1][j]);
                            }
                            else if(k+1 == j){
                                s[i][j] = min(s[i][j], s[i][k]+m[i][k]*m[k+1][j]);
                            }
                            else{
                                s[i][j] = min(s[i][j], s[i][k]+s[k+1][j]+m[i][k]*m[k+1][j]);
                            }
                        }
                    }
                }
            }
        }
        return s[0][n-1];
    }
};