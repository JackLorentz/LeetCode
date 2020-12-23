#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        //透過XOR就可以知道a or b結果和c在哪個位元有差異
        int t = (a | b) ^ c, cnt = 0, flip = 0;
        //如果XOR後為0則不需要任何更改
        if(t == 0)  return flip;
        //依序檢查XOR結果的每個位元
        while(t){
            if((t & 1) == 1){
                /**
                 * 假如這位元XOR結果為1表示a or b結果和c其中一個為1另一個為0
                 * 假如如a or b結果為1, 就表示a和b在這位元可能均為1, 這樣就需要a和b兩個位元均做更改
                 * 其他狀況只要a和b其中一個做更改即可
                 * */
                if((a>>cnt & 1) == 1 && (b>>cnt & 1) == 1)
                    flip += 2;
                else
                    flip++;
            }
            t >>= 1;
            cnt++;
        }
        return flip;
    }
};