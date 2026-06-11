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

/*
TreeNode* CreateBinaryTree(vector<int>& nums) {
    // if nums.size() == 0, return null
    if (nums.empty()) return nullptr;
    
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nums.at(0));
    q.push(root);
    
    // traverse the input array within while loop
    // and assign left and right children for the current node sequentially
    // stop the loop when the queue is empty or index i surpass the nums.size()
    int i = 1;
    while(!q.empty() && i < nums.size()) {
        TreeNode* temp = q.front();
        q.pop();
        
        if (nums.at(i) != -1 && i < nums.size()) {
            temp->left = new TreeNode(nums.at(i));
            q.push(temp->left);
        } 
        i++;
        if (nums.at(i) != -1 && i < nums.size()) {
            temp->right = new TreeNode(nums.at(i));
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
*/

class Solution {
    
private:
    void inorder(TreeNode* node, vector<int>& inorderArray) {
        if (!node) return;
        inorder(node->left, inorderArray);
        inorderArray.push_back(node->val);
        inorder(node->right, inorderArray);
    }
    
public: 
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> output;
        inorder(root, output);
        
        return output[k-1];
    }
};
