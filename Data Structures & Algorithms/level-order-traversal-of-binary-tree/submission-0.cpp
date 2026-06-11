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

        if (!root) 
            return vector<vector<int>>();

        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);

        while(!q.empty()){
            
            int tmpSize = q.size();
            vector<int> tmpVec;
            tmpVec.reserve(tmpSize);

            for(int i = 0; i < tmpSize; i++){
                TreeNode* tmp = q.front();
                q.pop();

                tmpVec.emplace_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            result.emplace_back(tmpVec);
        }
        return result;
    }
};
