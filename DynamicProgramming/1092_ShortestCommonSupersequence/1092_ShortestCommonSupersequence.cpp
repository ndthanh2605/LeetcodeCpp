
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int n1, n2;
    string str1, str2;
    map<pair<int, int>, string> cache;

    string Try(int i, int j) {
        if (i == n1)
            return str2.substr(j, n2 - j);
        if (j == n2)
            return str1.substr(i, n1 - i);

        auto itr = cache.find({ i, j });
        if (itr != cache.end())
            return itr->second;

        // same char
        if (str1[i] == str2[j]) {
            string rs = str1[i] + Try(i + 1, j + 1);
            cache[{i, j}] = rs;
            return rs;
        }

        string tmp1 = str1[i] + Try(i + 1, j);
        string tmp2 = str2[j] + Try(i, j + 1);

        if (tmp1.length() > tmp2.length()) {
            cache[{i, j}] = tmp2;
            return tmp2;
        }
        cache[{i, j}] = tmp1;
        return tmp1;
    }

    // backtrack => DP?
    string shortestCommonSupersequence(string str1, string str2) {
        this->str1 = str1;
        this->str2 = str2;
        n1 = str1.length();
        n2 = str2.length();
        
        return Try(0, 0);
    }
};

int main()
{
    Solution sln;
    cout << sln.shortestCommonSupersequence("bcaaacbbbcbdcaddadcacbdddcdcccdadadcbabaccbccdcdcbcaccacbbdcbabb",
        "dddbbdcbccaccbababaacbcbacdddcdabadcacddbacadabdabcdbaaabaccbdaa") << endl;

    return 0;
}
