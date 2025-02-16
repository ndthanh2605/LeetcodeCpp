
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            bool ok_prev = false, ok_next = false;
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    ok_prev = true;
                }
                else if (flowerbed[i - 1] == 0) {
                    ok_prev = true;
                }
                if (i == flowerbed.size() - 1) {
                    ok_next = true;
                }
                else if (flowerbed[i + 1] == 0) {
                    ok_next = true;
                }

                if (ok_prev && ok_next) {
                    flowerbed[i] = 1;
                    n--;
                    if (n == 0)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
