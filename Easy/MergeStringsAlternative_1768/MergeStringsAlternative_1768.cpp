
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if (word1.empty())
            return word2;
        if (word2.empty())
            return word1;

        string rs = "";
        stringstream ss;
        int p = 0;
        int l1 = word1.length(), l2 = word2.length();

        while (true)
        {
            if (p < l1) {
                ss << word1[p];
            }
            if (p < l2) {
                ss << word2[p];
            }
            p++;
            if (p >= l1 || p >= l2)
                break;
        }

        rs = ss.str();
        return rs;
    }
};

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
