#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        /**
         * 卡塔蘭數公式: h(n) = (1/n)*C(2n, n)
         * 卡塔蘭數使用時機: 當你有兩種操作, 其中一種操作(動作A)在執行順序上必須要優先於另一種操作(動作B), 
         * 而此時動作A和B各要做N次, 就可以用卡塔蘭數解出所有操作的排列可能數
         * 例如:
         * 1. stack permutation: 固定物件順序, 將所有物件push並pop出來, 計算所有操作排列可能
         * 2. 給個m*n的方格, 從左下角走到右上角, 其中只能往上和往右兩種走法, 且不得和對角線有交點
         * 3. 有16個人要買燒餅, 一個燒餅5元, 有8個人只有10元, 另外8個人只有5元, 老闆身上還沒錢找, 找出所有不會沒錢找的排隊可能數
         * 計算BST所有可能組成方式就跟stack permutation相同, 因為BST中序永遠是按照數字順序, 而不同的push和pop的二元樹搜尋方式就是後序或前序
         * (前序和中序, 後序和中序可以決定唯一二元樹)
         * */
        double catalan = 1.0;
        for(int i=1; i<=n; i++){
            catalan *= double(n+i) / double(i);
        }
        return round(catalan / double(n+1));
    }
};