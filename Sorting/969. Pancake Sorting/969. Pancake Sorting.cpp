
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
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();

        auto flip = [&](int idx) -> void
            {
                int l = 0;
                int r = idx;
                while (l <= r) {
                    swap(arr[l], arr[r]);
                    l++; r--;
                }
            };

        vector<int> rs;
        for (int i = n - 1; i > 0; i--) {
            // find the larget item in sub array (0 -> i)
            auto itr = max_element(arr.begin(), arr.begin() + i + 1);
            int maxIdx = itr - arr.begin();
            if (maxIdx == i) {
                continue;
            }

            // flip from start to that item => make the largest item at the start of arr
            if (maxIdx > 0) {
                flip(maxIdx);
                rs.push_back(maxIdx + 1);
            }

            // flip whole sub array (from start to i)
            flip(i);
            rs.push_back(i + 1);
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> arr = { 1,2,3 };
    vector<int> rs = sln.pancakeSort(arr);
    for (auto& i : rs) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
