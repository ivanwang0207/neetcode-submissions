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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& index, int l, int h){
        
        if (l > h) return nullptr;
        
        int currElement = preorder[index++];
        // find the index currElement in the inorder list
        int currIndex = l;
        while (currElement != inorder[currIndex] && currIndex <= h)
            currIndex++;
        
        TreeNode* newNode = new TreeNode(currElement);
        newNode->left = buildTree(preorder, inorder, index, l, currIndex - 1);
        newNode->right = buildTree(preorder, inorder, index, currIndex + 1, h);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildTree(preorder, inorder, index, 0, preorder.size() - 1);
    }
};
