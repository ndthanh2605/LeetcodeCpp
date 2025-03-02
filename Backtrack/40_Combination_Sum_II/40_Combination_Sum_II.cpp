
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 1) {
            if (candidates[0] != target) {
                return {};
            }
            return { {candidates[0]} };
        }

        set<int> elements;
        unordered_map<int, int> freqs;
        for (auto& i : candidates) {
            freqs[i]++;
            elements.insert(i);
        }
        candidates = vector<int>(elements.begin(), elements.end());
        int n = candidates.size();

        vector<vector<int>> rs;
        vector<int> cb;
        int sum = 0;

        // number of candidates[idx] in combination
        function<void(int)> Try = [&](int idx)
            {
                int v = candidates[idx];

                if (sum + v > target)
                    return;
                    
                // test use from 0 -> n times of v
                for (int j = 0; j <= freqs[v]; j++) {
                    sum += j * v;
                    if (sum > target) {
                        sum -= j * v;
                        break;
                    }

                    freqs[v] -= j;
                    for (int k = 0; k < j; k++) {
                        cb.push_back(v);
                    }


                    if (sum == target) {
                        // end case
                        rs.push_back(cb);
                        cout << " > add: ";
                        for (auto& i : cb) {
                            cout << i << " ";
                        }
                        cout << endl;
                    }
                    else {
                        if (idx == n - 1) {
                            // endcase
                        }
                        else if (sum < target) {
                            Try(idx + 1);
                        }
                    }

                    // backtrack
                    freqs[v] += j;
                    //cb = prevCb;
                    for (int k = 0; k < j; k++) {
                        cb.erase(cb.end() - 1);
                    }
                    sum -= j * v;
                }
            };

        Try(0);

        return rs;
    }
};

int main()
{
    Solution sln;
    //vector<int> candidates = { 32,10,32,5,25,9,18,23,28,24,10,33,6,24,32,18,10,28,17,18,13,22,7,25,22,17,28,13,17,32,19,6,7,17,7,28,21,12,8,6,31,13,34,24,24,31,8,29,16,20,12,25,29,6,15,16,19,30,17,23,27,31,17,29 };
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    cout << sln.combinationSum2(candidates, 8).size() << endl;

    return 0;
}
