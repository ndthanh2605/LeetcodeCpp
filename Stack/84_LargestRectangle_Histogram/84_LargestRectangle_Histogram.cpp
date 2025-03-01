
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return heights[0];

        vector<int> smLeft(n, -1);     // index of 1st smaller col in left
        stack<int> stLeft;
        for (int i = 0; i < n; i++) {
            int cur = heights[i];
            while (!stLeft.empty() && cur <= heights[stLeft.top()]) {
                stLeft.pop();
            }
            if (!stLeft.empty()) {
                smLeft[i] = stLeft.top();
            }
            stLeft.push(i);
        }

        vector<int> smRight(n, n);      // index of 1st smaller col in right
        stack<int> stRight;
        for (int i = n - 1; i >= 0; i--) {
            int cur = heights[i];
            while (!stRight.empty() && cur <= heights[stRight.top()]) {
                stRight.pop();
            }
            if (!stRight.empty()) {
                smRight[i] = stRight.top();
            }
            stRight.push(i);
        }
        for (auto& i : smRight) {
            cout << " " << i;
        }
        cout << endl;

        int rs = 0, tmp;
        for (int i = 0; i < n; i++) {
            tmp = heights[i] * (smRight[i] - 1 - smLeft[i]);
            rs = max(rs, tmp);
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> heights = { 2,1,2 };
    cout << sln.largestRectangleArea(heights) << endl;

    return 0;
}
