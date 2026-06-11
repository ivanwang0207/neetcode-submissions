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
    bool dfs(TreeNode* node, int lb, int hb) {
        // check if the current node is valid based on lb and hb 
        if (node->val <= lb || node->val >= hb) return false;

        // keep on calling dfs to check the validity of left and right 
        if (node->left) {
            if (!dfs(node->left, lb, node->val)) return false;
        }
        if (node->right) {
            if (!dfs(node->right, node->val, hb)) return false;
        }
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
