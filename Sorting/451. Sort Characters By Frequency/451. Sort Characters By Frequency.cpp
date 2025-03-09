
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <sstream>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        if (n <= 1)
            return s;

        int mx = max('Z', 'z');
        vector<int> cnt(mx + 1);
        for (auto& c : s) {
            cnt[c]++;
        }

        // build output
        priority_queue<pair<int, char>> q;
        for (int i = '0'; i <= mx; i++) {
            if (cnt[i]) {
                q.push({ cnt[i], (char)i });
            }
        }
        
        stringstream ss;
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            for (int i = 0; i < p.first; i++) {
                ss << p.second;
            }
        }

        return ss.str();
    }
};

int main()
{
    Solution sln;
    cout << sln.frequencySort("treerr") << endl;

    return 0;
}
