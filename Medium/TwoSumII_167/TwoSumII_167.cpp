
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size() - 1;

        while (p1 < p2)
        {
            if (numbers[p1] + numbers[p2] == target) {
                return { p1 + 1, p2 + 1 };
            }
            if (numbers[p1] + numbers[p2] < target) {
                // move left pointer because if keeping it, all right right pointer will lead to smaller sum than target
                p1++;
            }
            else {
                p2--;
            }
        }
        return { -1, -1 };
    }

};

int main()
{
    Solution sln;
    vector<int> numbers = { 2, 3, 4 };
    vector<int> rs = sln.twoSum(numbers, 6);
    cout << rs[0] << "," << rs[1] << endl;

    return 0;
}
