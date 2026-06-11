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

    // Building the sorted sequence dynamically:
    // the helper function recursively traverse the left node
    // and then process (add it to the sequence) the current node
    // and then traverse the right node
    void inorder(TreeNode* node, vector<int>& sequence) {
        if (!node) return;
        inorder(node->left, sequence);
        sequence.push_back(node->val);
        inorder(node->right, sequence);
    }
    
public: 
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> output;
        inorder(root, output);
        
        return output[k-1];
    }
};

// Since this a BST tree, the in-order traversal visits node in sorted order
// the helper function returns the sorted sequence and the k-1 smallest 
// can be found at index k-1 within that sequence

// time: O(n): traverse all elements in the sequence
// space: Skewed tree -> Worse case is O(n); balanced tree -> best case is O(logn)
