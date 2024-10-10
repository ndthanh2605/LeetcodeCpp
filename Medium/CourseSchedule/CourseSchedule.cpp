// CourseSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DUGraph {     // Directional Unweighted
public:
    int V;
    vector<vector<int>> adj;
    vector<int> indegrees;   // number of edges coming into each vertex

    DUGraph(int v) : V(v), adj(v), indegrees(v, 0) {}
    ~DUGraph() {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        indegrees[v] = indegrees[v] + 1;
    }

    bool checkCyclic() {    // using topology sort
        auto itr = find(indegrees.begin(), indegrees.end(), 0);
        if (itr == indegrees.end()) {
            return false;
        }

        // get all nodes with 0 indegree
        queue<int> nodes;
        while (itr != indegrees.end()) {
            nodes.push(itr - indegrees.begin());
            itr = find(itr + 1, indegrees.end(), 0);
        }

        // process
        int v;
        while (!nodes.empty()) {
            v = nodes.front();
            nodes.pop();

            if (indegrees[v] > 0)
                indegrees[v]--;
            for (auto& i : adj[v]) {
                if (indegrees[i] > 0) {
                    indegrees[i]--;
                    if (indegrees[i] == 0) {
                        nodes.push(i);
                    }
                }
            }
        }
        if (*max_element(indegrees.begin(), indegrees.end()) > 0)
            return false;
        return true;
    }
};

bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

int main()
{
    std::cout << "Course Schedule : Directional Graph > Topology Sort (with Indegree)!\n";
    return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    DUGraph g(numCourses);
    for (auto& pre : prerequisites) {
        g.addEdge(pre[1], pre[0]);
    }
    return g.checkCyclic();
}
