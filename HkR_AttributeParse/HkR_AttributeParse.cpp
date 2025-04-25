// https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <sstream>
#include <stack>

using namespace std;

struct Tag {
    string tagName;
    unordered_map<string, string> attributes;

    Tag(string& tag) : tagName(tag) {}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    unordered_map<string, Tag*> tags;
    stack<string> st;

    string line;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        line = line.substr(1, line.length() - 2);
        if (line[0] == '/') {       // close tag
            string tag = line.substr(1, line.length() - 1);
            if (!st.empty()) {
                string cur = st.top(); st.pop();
                int idx = cur.find('.');
                if (idx != string::npos) {
                    cur = string(cur.begin(), cur.begin() + idx);
                    st.push(cur);
                }
            }
            // cout << "close " << tag << endl;
        }
        else {                    // open tag
            string tag;
            istringstream iss(line);
            iss >> tag;
            if (!st.empty()) {
                tag = st.top() + "." + tag; st.pop();
            }
            st.push(tag);
            // cout << "open " << tag << endl;

            Tag* t = new Tag(tag);
            tags[tag] = t;

            string attr, eSign, value;
            while (iss >> attr >> eSign >> value) {
                value = value.substr(1, value.length() - 2);
                t->attributes[attr] = value;
            }
        }
    }
    // cout << "------------" << endl;
    // cout << "DONE READING" << endl;

    for (int i = 0; i < Q; i++) {
        getline(cin, line);
        int idx = line.find('~');
        string attr = string(line.begin() + idx + 1, line.end());
        string tag = string(line.begin(), line.begin() + idx);
        // cout << "query " << left << " > attr " << attr << endl;

        if (tags.count(tag) && tags[tag]->attributes.count(attr))
            cout << tags[tag]->attributes[attr] << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}
