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
    int goodNodes(TreeNode* root) {
        int currMaxVal = INT_MIN;
        return dfs(root, currMaxVal);
    }

    int dfs(TreeNode* node, int maxVal){
        if (!node) return 0;

        int temp = node->val >= maxVal? 1 : 0;
        maxVal = max(maxVal, node->val);

        int l = dfs(node->left, maxVal);
        int r = dfs(node->right, maxVal);

        return temp + l + r;
    }
};
