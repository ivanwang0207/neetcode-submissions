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

        // use queue to keep track of nodes 
        queue<TreeNode*> q;
        vector<vector<int>> result; // store the final level-order traversal
        q.push(root);

        /* use BFS with queue to traverse BST level by level
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            print(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        */

        // In each iteration, the nodes within the queue
        // belong to the same level, so we can directly use q.size() to 
        // determine how many nodes in the current level
        while(!q.empty()){

            int tmpSize = q.size(); // get the current count in the current level
            vector<int> tempVec;
            tempVec.reserve(tmpSize); // reserve memory

            // Traverse nodes in the current level
            for(int i = 0; i < tmpSize; i++){
                TreeNode* temp = q.front();
                tempVec.emplace_back(temp->val);
                q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            result.emplace_back(tempVec);
        }
        return result;
    }
};
