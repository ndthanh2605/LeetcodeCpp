
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    vector<int> indexes;
    int count = 0;

    void dfs(int s, vector<vector<int>>& isConnected) {
        indexes[s] = count;

        for (int i = 0; i < n; i++)
        {
            if (indexes[i] < 0 && isConnected[s][i])
                dfs(i, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected[0].size();
        indexes = vector<int>(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (indexes[i] < 0) {
                dfs(i, isConnected);
                count++;
            }
        }
        return count;
    }

};

int main()
{
    Solution sln;
    vector<vector<int>> isConnected = { {1,0,0}, {0,1,0}, {0,0,1} };
    cout << sln.findCircleNum(isConnected) << endl;

    return 0;
}
