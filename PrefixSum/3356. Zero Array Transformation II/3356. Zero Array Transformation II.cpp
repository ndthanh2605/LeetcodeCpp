
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        if (*max_element(nums.begin(), nums.end()) == 0)
            return 0;
        int m = queries.size();
        if (m == 0)
            return -1;

        // line sweeper (reverse prefix sum) : sum all sections
        // n = 3 => make array size n + 1 => [0, 0, 0, 0]
        // process each query: [0, 2, 1] => increase left & decrease (right + 1) by val
        // then build the sum array similar prefix sum & compare with nums
        // query 1: [1, 0, 0, -1] => [1, 1, 1, 0] => compare [1, 1, 1] with [2, 0, 2]
        // query 2: [2, 0, 0, -2] => [2, 2, 2, 0] => compare [2, 2, 2] with [2, 0, 2] => DONE

        auto checkQuerySum = [&](const vector<int>& lines) -> bool
            {
                vector<int> sum(n + 1);
                sum[0] = lines[0];
                //cout << "\n > query sum : " << sum[0];
                if (sum[0] < nums[0])
                    return false;
                for (int i = 1; i < n; i++) {  // the last item will always be 0
                    sum[i] = sum[i - 1] + lines[i];
                    cout << " " << sum[i];
                    // compare with nums
                    if (sum[i] < nums[i])
                        return false;
                }
                return true;
            };

        auto testKQueries = [&](int k) -> bool
            {
                vector<int> lines(n + 1, 0);

                for (int i = 0; i < k; i++) {
                    auto p = queries[i];
                    int l = p[0], r = p[1], w = p[2];
                    lines[l] += w;
                    lines[r + 1] -= w;
                }

                return checkQuerySum(lines);
            };

        // find best ans by binary search
        if (!testKQueries(m))
            return -1;

        int rs = m;
        int left = 1;
        int right = m;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (testKQueries(mid)) {
                right = mid - 1;
                rs = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
