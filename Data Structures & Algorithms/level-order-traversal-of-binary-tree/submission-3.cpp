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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();

        queue<TreeNode*> q;
        vector<vector<int>> results;
        q.push(root);

        while(!q.empty()) {
            int tmpSize = q.size();

            vector<int> tmpVec;
            tmpVec.reserve(tmpSize);

            for(int i = 0; i < tmpSize; i++) {
                
                auto* node = q.front();
                tmpVec.push_back(node->val);
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            results.push_back(tmpVec);
        }
        return results;
    }
};
