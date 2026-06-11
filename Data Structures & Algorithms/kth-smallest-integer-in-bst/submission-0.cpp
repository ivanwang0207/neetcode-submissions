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

    void inOrder(TreeNode* node, vector<int>& v){
        if (!node) return;

        inOrder(node->left, v);
        v.emplace_back(node->val);
        inOrder(node->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderVec;
        inOrder(root, inorderVec);
        return inorderVec[k - 1];
    }
};
