//substring要連續, subsequence則不用
#include <iostream>
#include <string>
using namespace std;

#define max(a,b) ((a>b)?a:b)

int main(void){
    string s = "aacabdkacaa";
    int max_idx = 0, max_l = 1;
    int len = s.length();
    bool P[len][len] = {false};
    //每個字元都是一個回文
    for(int i=0; i<len; i++){
        P[i][i] = true;
    }
    //若有2個字元連續重複出現, 最大長度至少為2
    for(int i=0; i<len-1; i++){
        if(s[i] == s[i+1]){
            P[i][i+1] = true;
            max_idx = i;
            max_l = 2;
        }
    }
    //從長度3~len依序尋找對稱位置是否相同, 若是則要記錄下來
    for(int l=3; l<=len; l++){
        for(int i=0; i<len-l+1; i++){
            int j = i+l-1;
            if(s[i] == s[j] && P[i+1][j-1]){
                P[i][j] = true;
                max_idx = i;
                max_l = l;
            }
        }
    }
    cout << s.substr(max_idx, max_l) << endl;
    return 0;
}