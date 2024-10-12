// ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> mins;

int minCost(vector<int>& costs, int n) {
    if (n < 2)
        return costs[n];

    if (mins[n] >= 0)
        return mins[n];

    mins[n] = costs[n] + min(minCost(costs, n - 1), minCost(costs, n - 2));
    //cout << "compute minCost at " << n << ": " << mins[n] << endl;
    return mins[n];
}

// bottom up approach
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n < 2)
        return 0;
    vector<int> minCost(n);
    minCost[0] = cost[0];
    minCost[1] = cost[1];
    for (int i = 2; i < n; i++) {
        minCost[i] = cost[i] + min(minCost[i - 1], minCost[i - 2]);
    }
    return min(minCost[n - 1], minCost[n - 2]);
}

// top down approach of Dynamic Programming
int minCostClimbingStairs_TopDown(vector<int>& cost) {
    cost.push_back(0);

    mins = vector<int>(cost.size(), -1);
    int rs = minCost(cost, cost.size()-1);
    //cout << rs;
    return rs;
}

int main()
{
    //vector<int> cost = vector<int>({ 10, 15, 20 });
    vector<int> cost = vector<int>({ 1,100,1,1,1,100,1,1,100,1 });

    minCostClimbingStairs(cost);
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
