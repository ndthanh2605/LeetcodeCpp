// DiameterOfBTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Solution.h"

class DiameterOfBTree {
public:
    int longestPath(TreeNode* node) {
        if (!node)
            return 0;
        if (!node->left && !node->right) {
            return 0;
        }
        //cout << " > checking node " << node->val << endl;
        return 1 + max(longestPath(node->left), longestPath(node->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int left = 0;
        int right = 0;
        if (root->left)
            left = 1 + longestPath(root->left);
        if (root->right)
            right = 1 + longestPath(root->right);

        return left + right;
    }
};

int main()
{
    vector<int> arr = { 4,-7,-3,INT_MAX,INT_MAX,-9,-3,9,-7,-4,INT_MAX,6,INT_MAX,-6,-6,INT_MAX,INT_MAX,0,6,5,INT_MAX,9,INT_MAX,INT_MAX,-1,-4,INT_MAX,INT_MAX,INT_MAX,-2 };

    vector<TreeNode*> arrNodes;
    TreeNode* tree = createTreeNodeFromArr(arr, arrNodes);
    printBT(tree);
    DiameterOfBTree s;
    cout << s.diameterOfBinaryTree(tree) << endl;
}
