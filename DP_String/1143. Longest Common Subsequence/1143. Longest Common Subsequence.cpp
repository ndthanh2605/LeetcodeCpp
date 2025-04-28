
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
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // add backtrace
        stringstream ss;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (dp[i][j] == 1 + dp[i + 1][j + 1]) {
                ss << text1[i];
                i++; j++;
            }
            else {
                if (dp[i][j] == dp[i + 1][j])
                    i++;
                else if (dp[i][j] == dp[i][j + 1])
                    j++;
            }
        }
        cout << ss.str() << endl;

        return dp[0][0];

        // function<int(int, int)> dp = [&](int i, int j) -> int
        // {
        //     if (i == n1 || j == n2)
        //         return 0;

        //     if (text1[i] == text2[j]) {
        //         return 1 + dp(i + 1, j + 1);
        //     }

        //     int dp1 = dp(i + 1, j);
        //     int dp2 = dp(i, j + 1);
        //     return max(dp1, dp2);
        // };
        // return dp(0, 0);
    }
};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
