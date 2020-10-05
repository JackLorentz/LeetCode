//LeetCode: 64. Minimum Path Sum
//Author: jackLorentz
#include <iostream>
#include <string>
using namespace std;

char input[10];
int matrix[3][3];
int cnt = 0;
int weight[3][3];

void show(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << weight[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(void){
    //輸入
    for(int i=0; i<3; i++){
        cin.getline(input, 10);
        for(int j=0; input[j]!='\0'; j++){
            if(input[j]!=' ' && cnt < 3){
                matrix[i][cnt] = (int)input[j]-48;
                weight[i][cnt] = matrix[i][cnt];
                cnt ++;
            }
        }
        cnt = 0;
    }
    //DP
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i-1 >= 0 && j-1 < 0)
                weight[i][j] += weight[i-1][j];
            else if(i-1 < 0 && j-1 >= 0)
                weight[i][j] += weight[i][j-1];
            else if(i-1 >= 0 && j-1 >=0){
                if(weight[i-1][j] > weight[i][j-1]){
                    weight[i][j] += weight[i][j-1];
                    weight[i-1][j] = weight[i][j-1];
                }
                else{
                    weight[i][j] += weight[i-1][j];
                    weight[i][j-1] = weight[i-1][j];
                }
            }
        }
    }
    cout << weight[2][2] << endl;
    return 0;
}

