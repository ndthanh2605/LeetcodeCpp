// ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;

        int p1 = 0, p2 = height.size() - 1;
        int area = (p2 - p1) * min(height[p1], height[p2]);
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                p1++;
            }
            else {
                p2--;
            }
            int tmp = (p2 - p1) * min(height[p1], height[p2]);
            if (area < tmp)
                area = tmp;
        }
        return area;
    }
};

int main()
{
    Solution sln;
    //vector<int> input = { 1,8,6,2,5,4,8,3,7 };
    vector<int> input = { 1,1 };
    cout << sln.maxArea(input) << endl;

    return 0;
}
