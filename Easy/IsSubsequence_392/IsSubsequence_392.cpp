
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;
        if (t.empty())
            return false;
        if (s.length() > t.length())
            return false;
        if (s == t)
            return true;

        int p1 = 0, p2 = 0;
        while (true)
        {
            while (t[p2] != s[p1])
            {
                p2++;
                if (p2 >= t.length())
                    return false;
            }
            p1++;
            p2++;
            if (p1 >= s.length()) {
                return true;
            }
        }


        return false;
    }
};

int main()
{
    Solution sln;
    cout << sln.isSubsequence("axc", "ahbgdc") << endl;

    return 0;
}
