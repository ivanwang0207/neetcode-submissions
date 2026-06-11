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

    void inorderIter(TreeNode* root, vector<int>& sequence) {
        if (!root) return;

        // use a stack to simulate the recursion of inorder
        stack<TreeNode*> s;
        TreeNode* temp = root;

        while(temp || !s.empty()) {

            // keep traversing as left as possible,
            // until the node is a null node
            while(temp){
                s.push(temp);
                temp = temp->left;
            }

            // popping node from the stack 
            // add the value of that node to the sequence
            temp = s.top();
            sequence.push_back(temp->val);
            s.pop();

            // and then move to the right subtree
            temp = temp->right;
        }
    }
    
public: 
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> output;
        // inorder(root, output);
        inorderIter(root, output);
        
        return output[k-1];
    }
};

// Since this a BST tree, the in-order traversal visits node in sorted order
// the helper function returns the sorted sequence and the k-1 smallest 
// can be found at index k-1 within that sequence

// time: O(n): traverse all elements in the sequence
// space: Skewed tree -> Worse case is O(n); balanced tree -> best case is O(logn)
