
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    vector<int> tmp;
    vector<int> finalRs;
    vector<bool> visited;
    int usedCount = 0;
    bool found = false;

    void print() {
        for (int i = 0; i < (2 * n - 1); i++)
        {
            cout << " " << i;
        }
        cout << endl;

        for (auto& i : tmp)
        {
            cout << " " << i;
        }
        cout << endl;
    }

    void Try(int idx) {
        if (found)
            return;
        if (tmp[idx] != 0 && idx < (2 * n - 1)) {
            Try(idx + 1);
            return;
        }

        // try place a number in the index
        for (int i = n; i > 0; i--)
        {
            if (found)
                return;
            if (visited[i])
                continue;

            int nextIdx = idx + i;
            if (i != 1) {
                if (nextIdx >= (2 * n - 1) || tmp[nextIdx] != 0)
                    continue;
            }

            cout << " > try idx " << idx << ": " << i << endl;
            int prevCount = usedCount;
            usedCount++;
            visited[i] = true;
            tmp[idx] = i;
            if (i != 1) {
                tmp[nextIdx] = i;
            }

            //print();
            if (usedCount == n || idx == 2 * n - 1) {
                // end case
                if (*min_element(tmp.begin(), tmp.end()) > 0) {
                    found = true;
                    cout << "FOUND!!!" << endl;
                    print();
                    finalRs = tmp;
                    return;
                }
            }
            else {
                Try(idx + 1);
            }

            // backtrack
            usedCount = prevCount;
            visited[i] = false;
            tmp[idx] = 0;
            if (i != 1) {
                tmp[nextIdx] = 0;
            }
            cout << " > backtrack idx " << idx << ": " << i << endl;
            //print();
        }
    }

    vector<int> constructDistancedSequence(int n) {
        if (n == 1) {
            return vector<int>({ 1 });
        }

        this->n = n;
        tmp = vector<int>(2 * n - 1, 0);
        visited = vector<bool>(n+1, false);
        Try(0);


        return finalRs;
    }
};

int main()
{
    Solution sln;
    sln.constructDistancedSequence(3);

    return 0;
}
