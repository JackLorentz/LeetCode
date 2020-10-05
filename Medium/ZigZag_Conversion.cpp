#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    /**
     * PAYPALISHIRING =>
     * PA H N
     * APLSIIG
     * Y I R
    */
    string s = "PAYPALISHIRING";
    int numRows = 3;
    vector< vector<char> > zigzag;
    int len = s.length();
    for(int i=0; i<numRows; i++){
        vector<char> tmp;
        zigzag.push_back(tmp);
    }
    int bias = 1;//每前進一個column會比正常位置多前進一格
    for(int i=0; i<len; i++){
        if(i / numRows == 0){
            zigzag[i].push_back(s[i]);
        }
        else{
            if((i+bias)/numRows > bias){
                bias++;
            }
            if(((i+bias)/numRows)%2 == 1){
                zigzag[numRows-1-(i+bias)%numRows].push_back(s[i]);
            }
            else{
                zigzag[(i+bias)%numRows].push_back(s[i]);
            }
        }
    }
    //string result = "";
    for(int i=0; i<numRows; i++){
        for(int j=0; j<static_cast<int>(zigzag[i].size()); j++){
            //result += zigzag[i][j];
            cout << zigzag[i][j];
        }
        cout << endl;
    }
    return 0;
}