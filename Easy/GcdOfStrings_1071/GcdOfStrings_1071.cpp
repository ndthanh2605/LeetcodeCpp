
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> rs;
        int _max = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++)
        {
            rs[i] = candies[i] + extraCandies >= _max;
        }

        return rs;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";

        int l = gcd(str1.length(), str2.length());

        string rs = str1.substr(0, l);
        return rs;
    }
};

int main()
{
    Solution sln;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << sln.gcdOfStrings(str1, str2) << endl;

    return 0;
}
