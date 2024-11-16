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

void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "L|--" : "R---");

        // print the value of the node
        std::cout << "(" << node->val << ")" << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? " |   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? " |   " : "    "), node->right, false);
    }
    else {
        std::cout << prefix;
        std::cout << (isLeft ? "L|--" : "R---");
        std::cout << "null" << std::endl;
    }
}

void printBT(const TreeNode* node)
{
    printBT("", node, false);
}

TreeNode* createTreeNodeFromArr(const vector<int>& arr, vector<TreeNode*>& arrNodes) {
    if (arr.empty())
        return NULL;
    
    arrNodes = vector<TreeNode*>(arr.size());
    TreeNode* root = new TreeNode(arr[0]);
    arrNodes[0] = root;
    
    int parentIdx, v;
    TreeNode* p;
    for (int i = 1; i < arr.size(); i++)
    {
        v = arr[i];
        TreeNode* n = NULL;
        if (v != INT_MAX) {
            n = new TreeNode(v);
        }
        parentIdx = (i - 1) / 2;
        p = arrNodes[parentIdx];
        if (p) {
            if (p->left) {
                p->right = n;
            }
            else {
                p->left = n;
            }
        }
        arrNodes[i] = n;
    }
    return root;
}


class Solution
{
public:
	vector<int> runningSum(vector<int>& nums);

    int maxDepth(TreeNode* root);       // recursion

    void moveZeroes(vector<int>& nums);     // 2 pointers

    ListNode* middleNode(ListNode* head);       // 2 pointers

    bool canConstruct(string ransomNote, string magazine);

    bool isPalindromeUsingArray(ListNode* head);

    bool isPalindrome(ListNode* head);      // use stack, lower performance

};

