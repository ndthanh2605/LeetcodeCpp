// CombinationSumII_40.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int target;
    vector<int> candidates;
    vector<bool> visited;
    vector<vector<int>> combinations;

    void Try(int minElement, int& sum, vector<int>& list) {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (visited[i])
                continue;
            int v = candidates[i];
            if (i >= 1 && v == candidates[i - 1] && !visited[i - 1])
                continue;
            if (v < minElement)
                continue;
            if (v > target - sum)
                continue;

            // choose
            visited[i] = true;
            sum += v;
            list.push_back(v);
            if (sum == target) {
                combinations.push_back(list);
            }
            else {
                Try(v, sum, list);
            }

            // not choose
            visited[i] = false;
            sum -= v;
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty())
            return combinations;
        if (*min_element(candidates.begin(), candidates.end()) > target)
            return combinations;

        this->target = target;
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        visited = vector<bool>(candidates.size(), false);

        int sum = 0;
        vector<int> list;
        Try(this->candidates[0], sum, list);

        return combinations;
    }

};

int main()
{
    Solution sln;

    vector<int> candidates = { 2,5,2,1,2 };
    vector<vector<int>> rs = sln.combinationSum2(candidates, 5);
    cout << rs.size() << endl;
    for (auto& list : rs)
    {
        cout << " > ";
        for (auto& i : list)
        {
            cout << "," << i;
        }
        cout << endl;
    }

    return 0;
}
