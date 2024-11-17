// CombinationSum_39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int target;
    vector<int> candidates;
    vector<vector<int>> combinations;

    void Try(int minElement, int& sum, vector<int>& list) {
        for (auto& i : candidates)
        {
            if (i < minElement)
                continue;
            if (i > target - sum)
                continue;
            // choose
            sum += i;
            list.push_back(i);
            if (sum == target) {
                combinations.push_back(list);
            }
            else {
                Try(i, sum, list);
            }

            // not choose
            sum -= i;
            list.erase(list.end() - 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty())
            return combinations;
        if (*min_element(candidates.begin(), candidates.end()) > target)
            return combinations;

        this->target = target;
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());

        int sum = 0;
        vector<int> list;
        Try(this->candidates[0], sum, list);

        return combinations;
    }
};

int main()
{
    Solution sln;
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    vector<vector<int>> rs = sln.combinationSum(candidates, 8);
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
