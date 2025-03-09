
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> origins;
        vector<Node*> nodes;

        // build all nodes
        Node* dummy = new Node(-1);
        Node* tmp = dummy;

        int cnt = 0;
        while (head) {
            origins[head] = cnt;

            tmp->next = new Node(head->val);
            tmp = tmp->next;
            tmp->random = head->random;

            nodes.push_back(tmp);
            head = head->next;
            cnt++;
        }

        // add links to random nodes
        for (auto& node : nodes) {
            if (node->random) {
                int idx = origins[node->random];
                node->random = nodes[idx];
            }
        }
        

        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
