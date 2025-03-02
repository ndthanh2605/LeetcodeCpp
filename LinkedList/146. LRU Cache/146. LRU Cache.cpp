
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    struct ListNode {
        int key, val;
        ListNode* next;
        ListNode* prev;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
        ListNode(int k, int v, ListNode* next) : key(k), val(v), next(next), prev(nullptr) {}
        ~ListNode() {}
    };

    int cap;
    unordered_map<int, ListNode*> lru;
    ListNode* head = nullptr, * tail = nullptr;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto itr = lru.find(key);
        if (itr == lru.end())
            return -1;

        // update linked list
        ListNode* node = itr->second;
        if (node == tail)
            return node->val;

        ListNode* prev = node->prev;
        ListNode* next = node->next;

        // remove node from link
        if (node == head) {
            head = next;
            next->prev = nullptr;
        }
        else {
            prev->next = next;
            next->prev = prev;
        }

        // add node to tail
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;

        return node->val;
    }

    void put(int key, int value) {
        auto itr = lru.find(key);
        if (itr != lru.end()) {
            itr->second->val = value;
            get(key);
            return;
        }

        // new key
        ListNode* node = new ListNode(key, value);

        if (lru.size() < cap) {
            if (!head) {
                // 1st item
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        else {
            // remove least used node
            ListNode* next = head->next;
            if (!next) {    // cap = 1
                tail = nullptr;
            }
            else {
                next->prev = nullptr;
            }

            lru.erase(head->key);
            delete head;
            head = next;

            if (tail) {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            else {
                head = tail = node;
            }
        }
        lru[key] = node;
    }
};

int main()
{
    LRUCache* lRUCache = new LRUCache(1);
    lRUCache->put(2, 1);
    lRUCache->get(2);
    lRUCache->put(3, 2);
    lRUCache->get(2);
    lRUCache->get(3);

    return 0;
}
