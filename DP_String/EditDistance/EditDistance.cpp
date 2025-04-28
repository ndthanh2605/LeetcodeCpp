// EditDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    enum Action { None, Insert, Delete, Replace };

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if (n1 == 0)
            return n2;
        if (n2 == 0)
            return n1;

        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1));
        vector<vector<Action>> act(n1 + 1, vector<Action>(n2 + 1, None));

        function<int(int, int)> dp = [&](int i, int j) -> int
            {
                if (i == 0)     return j;
                if (j == 0)     return i;

                if (mem[i][j] > 0) {
                    return mem[i][j];
                }

                if (word1[i - 1] == word2[j - 1]) { // do nothing
                    return mem[i][j] = dp(i - 1, j - 1);
                }
                int ins = dp(i, j - 1);
                int del = dp(i - 1, j);
                int rep = dp(i - 1, j - 1);

                int rs = min({ ins, del, rep });
                if (rs == ins)
                    act[i][j] = Insert;
                else if (rs == del)
                    act[i][j] = Delete;
                else if (rs == rep)
                    act[i][j] = Replace;
                return mem[i][j] = rs + 1;
            };

        int rs = dp(n1, n2);

        // backtrace transformation
        int i = n1, j = n2;
        while (i > 0 && j > 0) {
            if (act[i][j] == None) {
                i--; j--;
                continue;
            }
            string w1 = word1;
            if (act[i][j] == Replace) {
                w1[i - 1] = word2[j - 1];
                cout << "Replace idx " << i << " " << word1[i - 1] << ": " << word1 << " -> " << w1 << endl;
                i--; j--;
                word1 = w1;
                continue;
            }
            if (act[i][j] == Insert) {
                w1.insert(w1.begin() + i, word2[j - 1]);
                cout << "Insert idx " << i << " " << word2[j - 1] << ": " << word1 << " -> " << w1 << endl;
                j--;
                word1 = w1;
                continue;
            }
            if (act[i][j] == Delete) {
                w1.erase(w1.begin() + i - 1);
                cout << "Delete at idx " << i << " " << word1[i - 1] << ": " << word1 << " -> " << w1 << endl;
                i--;
                word1 = w1;
                continue;
            }
        }
        while (i > 0) {
            string w1 = word1;
            w1.erase(w1.begin() + i - 1);
            cout << "Delete at idx " << i << " " << word1[i - 1] << ": " << word1 << " -> " << w1 << endl;
            word1 = w1;
            i--;
        }

        while (j > 0) {
            string w1 = word1;
            w1.insert(w1.begin() + i, word2[j - 1]);
            cout << "Insert idx " << i << " " << word2[j - 1] << ": " << word1 << " -> " << w1 << endl;
            word1 = w1;
            j++;
        }

        return rs;
    }
};
int main()
{
    Solution sln;
    std::cout << sln.minDistance("horse", "ros") << endl;

    return 0;
}
