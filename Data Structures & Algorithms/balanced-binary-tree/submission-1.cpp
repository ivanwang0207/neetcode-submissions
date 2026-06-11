/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool result = 1;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* node, bool& isBalanced){

        if (!node) return 0;

        int l = dfs(node->left, isBalanced);
        int r = dfs(node->right, isBalanced);

        if (isBalanced)
            isBalanced = abs(l - r) > 1 ? 0 : 1;

        return max(l, r) + 1;
    }
};
