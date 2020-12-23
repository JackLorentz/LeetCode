#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //在Leetcode中將函式宣告成private會跑比較快
private:
    /**
     * 思路: 由於值只會出現在1-9之間, 所以可以將1-9進行2進位編碼, 比如1->(0 0000 0001) 2->(0 0000 0010) ... 9->(1 0000 0000)
     * 要成為偽回文條件為從根到葉子的每條路徑上最多只有一個數出現奇數次, 所以可以用dfs遍歷方式去將路徑上的值用XOR累積運算, 
     * 如果是偽回文其累積運算結果用二進位表示最多只會有一個位數是1, 因為出現偶數次該位數經過XOR必為0
     * 這題DFS要用遞迴做否則非葉子值無法重複利用
    */
    int dfs_traverse(TreeNode* cur, int freq){
        if(!cur)    return 0;
        freq = freq ^ (1<<(cur->val-1));
        if(!cur->left && !cur->right){
            if((freq & (freq-1)) == 0)  return 1;
            return 0;
        }
        return dfs_traverse(cur->left, freq) + dfs_traverse(cur->right, freq);
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs_traverse(root, 0);
    }
};