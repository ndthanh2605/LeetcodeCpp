
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* rs;
        if (list1->val > list2->val) {
            rs = list2;
            list2 = list2->next;
        }
        else {
            rs = list1;
            list1 = list1->next;
        }
        rs->next = merge2Lists(list1, list2);        

        return rs;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        int n = lists.size();
        function<ListNode*(int,int)> mergeLists = [&](int start, int stop) -> ListNode*
            {
                if (start == stop) {
                    return lists[start];
                }
                if (stop - start == 1) {
                    return merge2Lists(lists[start], lists[stop]);
                }

                int pivot = (start + stop) / 2;
                return merge2Lists(mergeLists(start, pivot), mergeLists(pivot+1, stop));
            };

        return mergeLists(0, n - 1);
    }
};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
