
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
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> getDistances(vector<int>&arr) {
            int n = arr.size();
            if (n == 1) {
                return { 0 };
            }

            unordered_map<int, vector<int>> m;      // value - indexes
            unordered_map<int, vector<long long>> prefix;

            for (int i = 0; i < n; i++) {
                int cur = arr[i];
                m[cur].push_back(i);
                if (prefix[cur].empty()) {
                    prefix[cur].push_back(0);
                }
                int sz = m[cur].size();
                long long lastPrefix = prefix[cur][sz - 1];
                prefix[cur].push_back(lastPrefix + i);
            }

            vector<long long> rs(n);
            for (auto& v : m) {
                vector<int> indexes = v.second;
                int k = indexes.size();
                for (int j = 0; j < k; j++) {
                    long long tmp = 0;
                    // calc sum before : indexes[j] is the value => sumBefore = value * j - prefix[j]
                    tmp += indexes[j] * (long)j - prefix[v.first][j];

                    // calc sum after => sumAfter = prefix[k] - prefix[j + 1] - value * (k - j - 1)
                    tmp += prefix[v.first][k] - prefix[v.first][j + 1] - indexes[j] * (long)(k - j - 1);
                    rs[indexes[j]] = tmp;
                }
            }
            return rs;
        }
};

int main()
{
    Solution sln;
    vector<int> arr = { 2,1,3,1,2,3,3 };
    cout << sln.getDistances(arr).size() << endl;

    return 0;
}
