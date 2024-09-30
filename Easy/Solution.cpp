#include "Solution.h"

vector<int> Solution::runningSum(vector<int>& nums)
{
    int l = nums.size();
    if (l < 1 || l > 1000)
        return nums;
    for (int i = 1; i < l; i++) {
        nums[i] = nums[i - 1] + nums[i];
    }
    return nums;
}

int Solution::maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
