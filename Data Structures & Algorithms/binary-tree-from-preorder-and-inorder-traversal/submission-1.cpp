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
    // helper function:
    // 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& index, int l, int h){
        if (l > h) return nullptr;
        
        // find the index of preorder[index] in inorder 
        int val = preorder[index++];
        int currIndex = l;
        while(val != inorder[currIndex]) {
            currIndex++;
        }

        // create TreeNode for the current value
        TreeNode* currNode = new TreeNode(val);

        // divide inorder based on the currIndex
        // left: l, currIndex
        currNode->left = buildTree(preorder, inorder, index, l, currIndex-1);
        // right: currIndex+1, h
        currNode->right = buildTree(preorder, inorder, index, currIndex+1, h);

        return currNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildTree(preorder, inorder, index, 0, inorder.size()-1);
    }
};
