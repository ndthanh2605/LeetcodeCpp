
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        if (n <= 1)
            return n;

        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++) {
            freq[text[i]]++;
        }



        int l = 0;
    }
};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
