
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> rs;
        vector<bool> visited(10, false);

        int sum = 0;
        vector<int> cb;

        function<void(int,int)> Try = [&](int start, int idx) -> void     // idx: from 0 -> (k-1)
            {
                for (int i = start; i < 10; i++) {
                    if (visited[i])
                        continue;

                    //visited[i] = true;
                    k--;
                    sum += i;
                    cb.push_back(i);

                    if (k == 0) {
                        // end case
                        if (sum == n) {
                            rs.insert(cb);
                            cout << " > push:";
                            for (auto& i : cb)   cout << " " << i;
                            cout << endl;
                        }
                    }
                    else if (k > 0) {
                        if (sum < n) {
                            Try(i + 1, idx + 1);
                        }
                    }

                    // backtrack
                    //visited[i] = false;
                    k++;
                    sum -= i;
                    cb.pop_back();
                }
            };

        Try(1, 0);
        return vector<vector<int>>(rs.begin(), rs.end());
    }
};

int main()
{
    Solution sln;
    cout << sln.combinationSum3(3, 9).size() << endl;

    return 0;
}
