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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	vector<int> runningSum(vector<int>& nums);

    int maxDepth(TreeNode* root);       // recursion

    void moveZeroes(vector<int>& nums);     // 2 pointers

    ListNode* middleNode(ListNode* head);       // 2 pointers

    bool canConstruct(string ransomNote, string magazine);

};

