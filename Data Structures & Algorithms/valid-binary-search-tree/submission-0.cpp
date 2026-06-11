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
    bool isValidBST(TreeNode* target, int leftBound, int rightBound){
        if (!target) return 1;

        if (target->val > leftBound && target->val < rightBound) {
            int newLeftBound = max(leftBound, target->val);
            int newRightBound = min(rightBound, target->val);

            return isValidBST(target->right, newLeftBound, rightBound) 
                && isValidBST(target->left, leftBound, newRightBound);
        } else {
            return 0;
        }
    }
};
