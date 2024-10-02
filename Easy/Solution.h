#pragma once

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<int> runningSum(vector<int>& nums);

    int maxDepth(TreeNode* root);       // recursion

    void moveZeroes(vector<int>& nums);     // use 2 pointers

    bool canConstruct(string ransomNote, string magazine);
};

