
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> stepsBob;
    vector<bool> visited;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void buildParent() {
        parent = vector<int>(n, INT_MAX);
        visited = vector<bool>(n, false);
        int tmp = 0;
        queue<int> q;
        q.push(tmp);

        while (!q.empty())
        {
            int node = q.front(); q.pop();
            visited[node] = true;

            for (auto& i : adj[node])
            {
                if (visited[i])
                    continue;
                q.push(i);
                parent[i] = node;
            }
        }
    }

    void dfs(int node, int steps, int cost, int &maxAmount, vector<int>& amount) {
        visited[node] = true;
        maxAmount = max(maxAmount, cost);

        for (auto& i : adj[node])
        {
            if (visited[i]) {
                continue;
            }

            int tmp = cost;
            if (steps + 1 == stepsBob[i]) {
                tmp += amount[i] / 2;
            }
            else if (steps + 1 < stepsBob[i]) {
                tmp += amount[i];
            }

            dfs(i, steps + 1, tmp, maxAmount, amount);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = edges.size() + 1;
        adj = vector<vector<int>>(n);

        for (auto& p : edges)
        {
            addEdge(p[0], p[1]);
        }
        buildParent();

        visited = vector<bool>(n, false);
        stepsBob = vector<int>(n, INT_MAX);
        stepsBob[bob] = 0;

        // move Bob
        while (bob > 0)
        {
            int p = parent[bob];
            stepsBob[p] = stepsBob[bob] + 1;
            bob = p;
        }

        //cout << " > Bob moves: ";
        //for (auto& i : stepsBob)
        //{
        //    cout << i << " ";
        //}
        //cout << endl;

        int maxAmount = - INT_MAX;
        dfs(0, 0, amount[0], maxAmount, amount);

        return maxAmount;
    }
};

int main()
{
    Solution sln;
    //vector<vector<int>> edges = { {0, 1}, {1, 2}, {1, 3}, {3, 4} };
    //vector<int> amount = { -2,4,2,-4,6 };
    
    vector<vector<int>> edges = { {0,2},{1,4},{1,6},{2,3},{2,8},{3,7},{4,5},{6,7} };
    vector<int> amount = { -1410,-9440,5536,-774,3044,7924,-2122,-1192,9166 };
    cout << sln.mostProfitablePath(edges, 1, amount) << endl;

    return 0;
}
