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

// if p and q are both smaller than the root -> goes to the left node
// if p and q are both greater than the root -> goes to the right node
// if one of p or q is the root itself, return the root directly

private:
    TreeNode* BST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return BST(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return BST(root->right, p, q);
        } else {
            return root;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return BST(root, p, q);
    }
};
