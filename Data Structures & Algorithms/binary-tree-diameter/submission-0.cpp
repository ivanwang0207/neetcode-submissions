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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0; // the global variable that store the current maximum res
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res){
        if (!root) return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right); // update res if left + right is greater than res
        return 1 + max(left, right); // return the larger dfs either from left or right
    }
};
