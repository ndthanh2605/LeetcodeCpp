// TrappingRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;

        int maxL = height[0], maxR = height[height.size() - 1];
        int pL = 0, pR = height.size() - 1;

        int rs = 0;
        while (pL != pR)
        {
            // move pointers
            if (height[pL] <= height[pR]) {
                pL++;
                if (height[pL] < maxL)
                    rs += maxL - height[pL];
                else
                    maxL = height[pL];
            }
            else {
                pR--;
                if (height[pR] < maxR)
                    rs += maxR - height[pR];
                else
                    maxR = height[pR];
            }
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    //vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    vector<int> heights = { 4,2,0,3,2,5 };
    cout << sln.trap(heights) << endl;
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
