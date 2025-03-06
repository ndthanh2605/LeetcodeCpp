
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
    bool checkPowersOfThree(int n) {
        int mod = n % 3;
        if (mod == 2)
            return false;

        // build list of 3^x until 3^x > n => m < log3(n)
        int m = log(n) / log(3);
        vector<int> powers(m + 1, 1);       //    1, 3, 9...
        vector<int> prefix(m + 2, 0);       // 0, 1, 4, 12...
        for (int i = 1; i < m + 1; i++) {
            powers[i] = pow(3, i);
            prefix[i] = prefix[i - 1] + powers[i];
        }

        int sum = 0;
        // backtrack: select or skip an element in list
        function<bool(int)> Try = [&](int idx) -> bool
            {
                if (idx < 0) {
                    // end case
                    return sum == n;
                }

                int cur = powers[idx];
                if (sum + cur > n) {
                    return Try(idx - 1);
                }

                sum += cur;
                if (sum == n) {
                    return true;
                }
                if (Try(idx - 1))
                    return true;
                sum -= cur;

                if (Try(idx - 1))
                    return true;
                return false;
            };

        return Try(powers.size() - 1);
    }
};

int main()
{
    Solution sln;
    cout << sln.checkPowersOfThree(15471) << endl;

    return 0;
}
