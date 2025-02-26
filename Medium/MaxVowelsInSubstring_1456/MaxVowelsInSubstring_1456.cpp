
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {      // only lower case
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            break;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int tmp = 0, rs;

        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                tmp++;
        }
        rs = tmp;

        for (int i = k; i < s.length(); i++)        // i is ending indx of sliding window
        {
            if (isVowel(s[i - k]))
                tmp--;
            if (isVowel(s[i]))
                tmp++;
            if (tmp > rs)
                rs = tmp;
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    cout << sln.maxVowels("weallloveyou", 7) << endl;

    return 0;
}
