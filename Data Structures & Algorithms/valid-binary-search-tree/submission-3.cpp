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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root->left, INT32_MIN, root->val) && 
            isValidBST(root->right, root->val, INT32_MAX);
    }

    bool isValidBST(TreeNode* node, int leftBound, int rightBound) {

        if (!node) return true;
        if (node->val <= leftBound || node->val >= rightBound) return false;        

        // check left and right node with updated boundaries
        return isValidBST(node->left, leftBound, node->val) &&
            isValidBST(node->right, node->val, rightBound);
    }
};
