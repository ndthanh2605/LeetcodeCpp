
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alts(gain.size() + 1, 0);
        for (int i = 1; i < alts.size(); i++)
        {
            alts[i] = alts[i - 1] + gain[i - 1];
        }

        return *max_element(alts.begin(), alts.end());
    }
};

int main()
{
    Solution sln;
    //cout << sln.largestAltitude() << endl;

    return 0;
}
