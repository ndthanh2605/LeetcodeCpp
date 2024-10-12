// NetworkDelayTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
public:
    int From, To, W;

    Edge(int u, int v, int w) : From(u), To(v), W(w) {}
    ~Edge() {}
};

class DWGraph {
public:
    int V;
    vector<vector<Edge>> Adj;
    vector<int> minCost;

    DWGraph(int v) : V(v), Adj(v + 1), minCost(V + 1, INT_MAX) {}
    ~DWGraph() {}

    void addEdge(int u, int v, int w) {
        Adj[u].push_back(Edge(u, v, w));
    }

    int dijkstra(int s) {
        minCost[0] = 0;
        minCost[s] = 0;

        vector<bool> visited(V + 1, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({ 0, s });

        vector<int> tmp;
        int c, u;
        while (!q.empty())
        {
            tmp = q.top();
            q.pop();

            c = tmp[0];     // cost
            u = tmp[1];     // node

            if (visited[u])
                continue;

            //cout << "- check cost at " << u << " : " << c << endl;
            visited[u] = true;
            minCost[u] = c;
            for (auto& e : Adj[u])
            {
                int cost = c + e.W;
                if (cost < minCost[e.To]) {
                    minCost[e.To] = cost;
                }
                q.push({ minCost[e.To], e.To });
                //cout << "  > add adj " << e.To << ", cost " << minCost[e.To] << endl;
            }
        }
        
        int rs = 0;
        for (auto& c : minCost)
        {
            if (c > rs)
                rs = c;
        }
        if (rs == INT_MAX)
            rs = -1;
        return rs;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    DWGraph g(n);
    for (int i = 0; i < times.size(); i++)
    {
        g.addEdge(times[i][0], times[i][1], times[i][2]);
    }
    return g.dijkstra(k);
}

int main()
{
    vector<vector<int>> times;
    times.push_back({ 1, 2, 1 });
    //times.push_back({ 2, 3, 1 });
    //times.push_back({ 3, 4, 1 });
    cout << networkDelayTime(times, 2, 2) << endl;
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
