
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int f(int x) {
        int rs = 0;
        while (x > 0) {
            int tmp = x % 10;
            rs += tmp * tmp;
            x /= 10;
        }
        return rs;
    }

    bool isHappy(int n) {
        if (n == 1)
            return true;
        int slow = n;
        int fast = f(n);
        while (fast != slow) {
            slow = f(slow);
            fast = f(f(fast));
        }
        return slow == 1;
    }
};

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
