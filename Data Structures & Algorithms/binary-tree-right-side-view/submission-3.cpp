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

        if (!root) 
            return vector<int>();

        vector<int> result;

        queue<TreeNode*> q;
        vector<vector<int>> container;
        q.push(root);

        while(!q.empty()){
            int tmp_size = q.size();
            vector<int> v;
            for(int i = 0; i < tmp_size; i++){
                auto node = q.front();
                v.emplace_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            container.emplace_back(v);
        }

        for(int i = 0; i < container.size(); i++){
            result.emplace_back(container[i].back());
        }
        return result;
    }
};
