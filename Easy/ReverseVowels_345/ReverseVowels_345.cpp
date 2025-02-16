
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - ('A' - 'a');
        }
        return c;
    }

    bool isVowel(char c) {
        char _c = toLower(c);
        auto itr = find(vowels.begin(), vowels.end(), _c);
        if (itr != vowels.end())
            return true;
        return false;
    }

    string reverseVowels(string s) {
        if (s.length() <= 1)
            return s;

        int p1 = 0, p2 = s.length() - 1;
        while (p1 <= p2)
        {
            while (!isVowel(s[p1])) {
                p1++;
                if (p1 >= s.length())
                    break;
            }
            while (!isVowel(s[p2])) {
                p2--;
                if (p2 == 0)
                    break;
            }
            if (p1 > p2)
                break;
            
            swap(s[p1], s[p2]);
            p1++;
            p2--;
        }
        return s;
    }
};

int main()
{
    Solution sln;
    cout << sln.reverseVowels("leetcode") << endl;

    return 0;
}
