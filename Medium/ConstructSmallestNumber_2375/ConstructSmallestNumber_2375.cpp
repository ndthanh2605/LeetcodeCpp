
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    int n;
    string pat;
    string tmp, rs;
    vector<bool> visited = vector<bool>(10, false);
    bool found = false;

    void Try(int idx) {
        if (found)
            return;

        for (int i = 1; i < 10; i++)
        {
            if (visited[i])
                continue;

            if (idx > 0) {
                if (pat[idx - 1] == 'I') {
                    if (i + '0' < tmp[idx - 1])
                        continue;
                }
                else if (pat[idx - 1] == 'D') {
                    if (i + '0' > tmp[idx - 1])
                        continue;
                }
            }

            // try i at index idx
            visited[i] = true;
            tmp[idx] = i + '0';

            //cout << " > try " << i << " at idx " << idx << endl;

            if (idx == n) {
                // end case
                found = true;
                rs = tmp;
                return;
            }
            else {
                Try(idx + 1);
            }

            // backtrack
            visited[i] = false;
            tmp.replace(idx, 1, " ");
        }
    }

    string smallestNumber(string pattern) {
        pat = pattern;
        n = pattern.length();

        stringstream ss;
        for (int i = 0; i <= n; i++)
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
    cout << sln.smallestNumber("IIIDIDDD") << endl;

    return 0;
}
