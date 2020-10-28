#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int num = 8;
    vector<int> result(num+1, 0);
    int n = 0, tmp = 0;
    while(n <= num){
        if(n <= 1){
            result[n] = n;
            cout << result[n] << endl;
        }
        else{
            //判斷2的指數倍
            if(n > 0 && (n & n-1) == 0){
                tmp = n;
            }
            result[n] = result[n-tmp] + 1;
            cout << result[n] << endl; 
        }
        n++;
    }
    return 0;
}

/**
 * Python Version
 * class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        result = [0]*(num+1)
        n = tmp = 0
        while n <= num:
            if n <= 1:
                result[n] = n
            else:
                if n > 0 and (n & n-1) == 0:
                    tmp = n
                result[n] = result[n-tmp] + 1
            n += 1
        return result;
*/