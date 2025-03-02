
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* s = head;
        ListNode* f = head;
        bool cycle = false;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                cycle = true;
                break;
            }
        }
        if (!cycle) {
            return nullptr;
        }
        // reset slow to head & move both by the same pace
        s = head;
        while (true) {
            s = s->next;
            f = f->next;
            if (s == f) {
                return s;
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
