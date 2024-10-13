// LongestCommonPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    char c;
    unordered_map<char, Node*> nexts;
    bool isTerminal = false;

    Node(char _c) : c(_c) {}
    ~Node() {}
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(const string& w) {
        Node* tmp = root;
        for (auto& c : w)
        {
            if (tmp->nexts.count(c) == 0) {
                Node* n = new Node(c);
                tmp->nexts[c] = n;
            }
            tmp = tmp->nexts[c];
        }
        tmp->isTerminal = true;
    }

    bool search(const string& w) {
        Node* tmp = root;
        for (auto& c : w)
        {
            if (tmp->nexts.count(c) == 0)
                return false;
            tmp = tmp->nexts[c];
        }
        return tmp->isTerminal;
    }

    int tryInserting(const string& w) {
        Node* tmp = root;
        int rs = 0;
        for (auto& c : w)
        {
            if (tmp->nexts.count(c) == 0) {
                return rs;
            }
            tmp = tmp->nexts[c];
            rs++;
        }
        return w.length();
    }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie trie;
    trie.insert(strs[0]);
    int rs = strs[0].length(), tmp;
    for (int i = 1; i < strs.size(); i++)
    {
        tmp = trie.tryInserting(strs[i]);
        if (tmp == 0)
            return "";
        if (tmp < rs) {
            rs = tmp;
        }
    }
    cout << rs << endl;
    return strs[0].substr(0, rs);
}

int main()
{
    //vector<string> strs = vector<string>{ "flower","flow","flight" };
    vector<string> strs = vector<string>{ "dog","racecar","car" };
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
