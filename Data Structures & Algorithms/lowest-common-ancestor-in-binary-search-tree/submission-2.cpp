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
    // edge case: nums.size() == 0
    if (nums.empty()) return nullptr;
    
    // use a queue to keep track of nodes whose children need to be assigned
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nums[0]);
    q.push(root);
    
    // Process nodes level by level until all the elements are traversed
    int i = 1;
    while(!q.empty() && i < nums.size()) {
        TreeNode* temp = q.front();
        q.pop();
        
        if (nums[i] != -1 && i < nums.size()){
            temp->left = new TreeNode(nums[i]);
            q.push(temp->left);
        }
        i++;
        if (nums[i] != -1 && i < nums.size()){
            temp->right = new TreeNode(nums[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
*/

class Solution {
    
public: 
    
    // A LCA node is found if p and q are on different sides of the current node, then the current node is their LCA. Otherwise, the LCA lies in the subtree that contains both p and q.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        // if p and q are both the right or left
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

// int main() {
//     vector<int> test1 = {5,3,8,1,4,7,9,-1,2}; // level-order traversal
//     TreeNode* p = new TreeNode(3);
//     TreeNode* q = new TreeNode(8);
//     TreeNode* root = CreateBinaryTree(test1);
    
//     p = new TreeNode(3);
//     q = new TreeNode(4);
    
//     Solution solution;
//     TreeNode* lcaNode = solution.lowestCommonAncestor(root, p, q);
    
//     std::cout << "lca: " << lcaNode->val << std::endl;
// }
