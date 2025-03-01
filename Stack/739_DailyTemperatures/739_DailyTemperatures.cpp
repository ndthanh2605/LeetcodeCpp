
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if (n == 1)
            return { 0 };

        stack<int> st;      // store index
        vector<int> rs(n, 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int cur = temperatures[i];
            while (!st.empty() && cur >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                rs[i] = st.top() - i;
            }
            st.push(i);
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 73,74,75,71,69,72,76,73 };
    vector<int> rs = sln.dailyTemperatures(nums);
    for (auto& i : rs)
    {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
