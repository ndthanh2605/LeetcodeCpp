
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    int n, k;
    string tmp, rs = "";
    int count = 0;
    bool found = false;

    void Try(int idx) {
        if (found)
            return;

        for (int i = 0; i < 3; i++)
        {
            if (idx > 0) {
                if (tmp[idx - 1] == 'a' + i) {
                    continue;
                }
            }
            tmp[idx] = 'a' + i;
            if (idx == n - 1) {
                // end case
                count++;
                if (count == k) {
                    found = true;
                    rs = tmp;
                    return;
                }
            }
            else {
                Try(idx + 1);
            }

            // backtrack
            tmp.replace(idx, 1, " ");
        }
    }

    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;

        stringstream ss;
        for (int i = 0; i < n; i++)
        {
            ss << " ";
        }
        tmp = ss.str();

        Try(0);

        return rs;
    }
};

int main()
{
    Solution sln;
    cout << sln.getHappyString(3, 9) << endl;

    return 0;
}
