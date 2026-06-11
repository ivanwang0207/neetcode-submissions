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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();

        // BFS
        queue<TreeNode*> q;
        q.push(root);
        vector<int> results;
        
        while(!q.empty()) {
            int count = q.size();

            for(int i = 0; i < count; i++) {
                auto* node = q.front();
                q.pop();

                if (i == count - 1) {
                    results.push_back(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return results;
    }
};
