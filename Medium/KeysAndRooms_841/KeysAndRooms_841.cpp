
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    vector<bool> visited;
    int count = 0;

    void dfs(vector<vector<int>>& rooms, int r) {
        visited[r] = true;
        count++;
        if (count == n)
            return;

        vector<int> nexts = rooms[r];
        for (auto& n : nexts)
        {
            if (visited[n])
                continue;
            dfs(rooms, n);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        visited = vector<bool>(n, false);
        dfs(rooms, 0);
        return (count == n);
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> rooms = { {2}, {}, {1} };
    cout << sln.canVisitAllRooms(rooms) << endl;
    
    
    return 0;
}
