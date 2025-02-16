
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Node {
public:
    char c = '\0';
    //unordered_map<char, Node*> nexts;
    vector<Node*> nexts;
    bool ended = false;

    Node(char _c) : c(_c), nexts(26, NULL) {}
    ~Node() {}
};

class Trie {
public:
    Node* start;

    Trie() {
        start = new Node('\0');
    }

    void insert(string word) {
        Node* node = start;
        for (auto& c : word)
        {
            //if (node->nexts.count(c) == 0) {
            if (node->nexts[c - 'a'] == NULL) {
                Node* n = new Node(c);
                node->nexts[c - 'a'] = n;
            }
            node = node->nexts[c - 'a'];
        }
        node->ended = true;
    }

    bool search(string word) {
        Node* node = start;
        for (auto& c : word)
        {
            //if (node->nexts.count(c) == 0)
            if (node->nexts[c - 'a'] == NULL)
                return false;
            node = node->nexts[c - 'a'];
        }
        return node->ended;
    }

    bool startsWith(string prefix) {
        Node* node = start;
        for (auto& c : prefix)
        {
            //if (node->nexts.count(c) == 0)
            if (node->nexts[c - 'a'] == NULL)
                return false;
            node = node->nexts[c - 'a'];
        }
        return true;
    }
};

class Solution {
public:

};

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
