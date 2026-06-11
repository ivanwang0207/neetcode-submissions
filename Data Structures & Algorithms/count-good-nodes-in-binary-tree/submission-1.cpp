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

private:
    int dfs(TreeNode* root, int maxVal) {
        if (!root) return 0;
        if (root->val >= maxVal) {
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        } else {
            return dfs(root->left, maxVal) + dfs(root->right, maxVal);
        }
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val);
    }
};
