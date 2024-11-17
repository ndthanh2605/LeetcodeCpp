// GenerateParentheses_22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<int> leftCount, rightCount;
    vector<string> strings;

    void Try(const string& str, int idx) {
        leftCount[idx] = leftCount[idx - 1];
        rightCount[idx] = rightCount[idx - 1];

        for (int i = 0; i < 2; i++)
        {
            if (leftCount[idx] == n && i == 0)
                continue;
            if (rightCount[idx] == leftCount[idx] && i == 1)
                continue;

            string str2 = str + ((i == 0) ? '(' : ')');
            if (i == 0)
                leftCount[idx]++;
            else
                rightCount[idx]++;

            if (idx == n * 2 - 2) {
                strings.push_back(str2 + ')');
            }
            else {
                Try(str2, idx + 1);
            }

            // backtrack
            if (i == 0)
                leftCount[idx]--;
            else
                rightCount[idx]--;

        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> rs;
        if (n == 1) {
            rs.push_back("()");
            return rs;
        }
        leftCount = vector<int>(n * 2, 1);
        rightCount = vector<int>(n * 2, 0);

        this->n = n;
        Try("(", 1);

        return strings;
    }
};

int main()
{
    Solution sln;
    vector<string> rs = sln.generateParenthesis(3);
    cout << rs.size() << endl;
    for (auto& s : rs)
    {
        cout << " " << s;
    }
    cout << endl;

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
