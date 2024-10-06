#include "Solution.h"

#include <iostream>
#include <stack>

using namespace std;

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

void Solution::moveZeroes(vector<int>& nums)
{
    if (nums.size() <= 1) {
        return;
    }

    int left = 0, right = 0;
    // find 1st index of 0
    for (; left < nums.size(); left++) {
        if (nums[left] == 0)
            break;
    }
    if (left == nums.size()) {
        // no 0 found
        return;
    }

    for (right = left + 1; right < nums.size(); right++) {
        if (nums[right] != 0) {
            swap(nums[right], nums[left]);
            left++;
        }
    }
}

ListNode* Solution::middleNode(ListNode* head)
{
    ListNode* node = head;      // fast pointer
    ListNode* middle = head;    // slow pointer
    bool nextMiddle = true;     // flag to stop slow pointer after every 1 move
    while (node->next) {
        node = node->next;
        if (nextMiddle) {
            middle = middle->next;
        }
        nextMiddle = !nextMiddle;
    }
    return middle;
}

bool Solution::canConstruct(string ransomNote, string magazine)
{
    // last index of every char
    vector<int> lastIndexes(26, 0);

    for (char c : ransomNote) {
        size_t idx = magazine.find(c, lastIndexes[c - 'a']);
        if (idx == string::npos)
            return false;

        // update last idx
        lastIndexes[c - 'a'] = idx + 1;
    }
    return true;
}

bool Solution::isPalindromeUsingArray(ListNode* head)
{
    vector<int> values;
    ListNode* tmp = head;
    while (tmp) {
        values.push_back(tmp->val);
        tmp = tmp->next;
    }
    cout << endl;

    for (int i = 0, j = values.size() - 1; i < values.size(), j >= 0; i++, j--)
    {
        if (i >= j)
            break;
        if (values[i] != values[j])
            return false;
    }

    return true;
}

bool Solution::isPalindrome(ListNode* head)
{
    stack<int> stack;
    ListNode* tmp = head;
    while (tmp) {
        stack.push(tmp->val);
        tmp = tmp->next;
    }
    
    int size = stack.size();
    int v;
    while (!stack.empty())
    {
        if (stack.size() <= (size / 2.0))
            return true;

        v = stack.top();
        stack.pop();

        if (v != head->val) {
            return false;
        }
        head = head->next;
    }

    return true;
}
