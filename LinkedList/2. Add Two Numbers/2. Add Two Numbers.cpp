
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}


};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        int rem = 0;

        int x, y, sum;
        while (l1 || l2 || rem > 0) {
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;

            sum = x + y + rem;
            rem = sum / 10;
            sum = sum % 10;

            tmp->next = new ListNode(sum);
            tmp = tmp->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        ListNode* rs = dummy->next;
        delete dummy;
        return rs;
    }
};

int main()
{
    Solution sln;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    
    ListNode *rs = sln.addTwoNumbers(l1, l2);
    while (rs) {
        cout << rs->val << " ";
        rs = rs->next;
    }
    cout << endl;

    return 0;
}
