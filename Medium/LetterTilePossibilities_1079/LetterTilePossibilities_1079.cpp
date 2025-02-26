
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    string src;
    vector<bool> visited;
    unordered_set<string> poss;
    string tmp;

    void Try(int idx, int l) {
        for (int i = 0; i < src.size(); i++)
        {
            if (visited[i])
                continue;

            // try char i at index idx
            visited[i] = true;
            tmp[idx] = src[i];

            if (idx == l - 1) {
                // end case
                poss.insert(tmp);
                //cout << " > add str " << tmp << endl;
            }
            else {
                Try(idx + 1, l);
            }

            // backtrack
            visited[i] = false;
            tmp.replace(idx, 1, " ");
        }
    }

    void makePoss(int l) {
        stringstream ss;
        for (int i = 0; i < l; i++)
        {
            ss << " ";
        }
        tmp = ss.str();

        Try(0, l);
    }

    int numTilePossibilities(string tiles) {
        src = tiles;

        for (int i = 1; i <= tiles.size(); i++)
        {
            visited = vector<bool>(tiles.size(), false);
            makePoss(i);
        }

        return poss.size();
    }
};

int main()
{
    Solution sln;
    cout << sln.numTilePossibilities("AAABBC") << endl;

    return 0;
}
