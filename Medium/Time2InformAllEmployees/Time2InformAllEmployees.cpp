// Time2InformAllEmployees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class DirectedGrapth {
public:
    int V;
    vector<vector<int>> adj;

    DirectedGrapth(int v) : V(v), adj(v + 1) {}
    ~DirectedGrapth() {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void print() {
        cout << "V : " << V << ", ADJ :" << endl;
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << ", ";
            }
            cout << ">" << endl;
        }
        cout << "_____";
    }
};


int dfs(DirectedGrapth& g, int v, vector<bool>& visited, vector<int>& sumTime, vector<int>& informTime);
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);

int main()
{
    vector<int> manager = vector<int>{ 2, 2, -1, 2, 2, 2 };
    vector<int> informTime = vector<int>{ 0, 0, 1, 0, 0, 0 };
    cout << numOfMinutes(6, 2, manager, informTime) << endl;


    manager = vector<int>{ 2, 2, 4, 6, -1, 4, 4, 5 };
    informTime = vector<int>{ 0, 0, 4, 0, 7, 3, 6, 0 };
    cout << numOfMinutes(8, 4, manager, informTime) << endl;

}


int dfs(DirectedGrapth& g, int v, vector<bool>& visited, vector<int>& sumTime, vector<int>& informTime) {
    if (visited[v])
        return sumTime[v];

    visited[v] = true;
    int time, maxTimeOfChildren = 0;
    for (auto& i : g.adj[v])
    {
        time = dfs(g, i, visited, sumTime, informTime);
        if (maxTimeOfChildren < time) {
            maxTimeOfChildren = time;
        }
    }
    sumTime[v] = maxTimeOfChildren + informTime[v];

    return sumTime[v];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    cout << n << " " << headID << endl;
    for (auto& i : manager)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (auto& i : informTime)
    {
        cout << i << ", ";
    }
    cout << endl;

    DirectedGrapth g(n);
    for (int i = 0; i < n; i++)
    {
        if (i == headID)
            continue;
        g.addEdge(manager[i], i);
    }

    vector<bool> visited(n, false);
    vector<int> sumTime(n, 0);
    int rs = dfs(g, headID, visited, sumTime, informTime);

    return rs;
}