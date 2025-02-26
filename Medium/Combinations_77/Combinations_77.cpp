// Combinations_77.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> tmp;
    vector<bool> visited;
    vector<int> tmp;

    void Try(int n, int k, int idx) {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            if (idx > 0 && tmp[idx - 1] > i)        // only build combinations in increasing order
                continue;
            
            visited[i] = true;
            tmp[idx] = i;
            
            if (idx == k - 1) {
                tmp.push_back(tmp);
            }
            else {
                Try(n, k, idx + 1);
            }

            // backtrack
            visited[i] = false;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        visited = vector<bool>(n + 1, false);
        tmp = vector<int>(k);

        Try(n, k, 0);

        return tmp;
    }
};

int main()
{
    Solution sln;
    cout << sln.combine(4, 2).size() << endl;

    return 0;
}
