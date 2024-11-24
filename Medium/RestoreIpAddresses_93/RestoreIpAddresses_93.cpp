// RestoreIpAddresses_93.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    bool valid(string s) {
        if (s.empty() || s.length() > 3)
            return false;
        if (s.length() > 1 && s[0] == '0')
            return false;
        int v = stoi(s);
        if (v > 255)
            return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> rs;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    for (int l = 1; l <= 3; l++)
                    {
                        if (i + j + k + l == s.length()) {
                            //cout << endl;
                            string p01 = s.substr(0, i);
                            //cout << p01 << " ";
                            if (!valid(p01))
                                continue;
                            string p02 = s.substr(i, j);
                            //cout << p02 << " ";
                            if (!valid(p02))
                                continue;
                            string p03 = s.substr(i+j, k);
                            //cout << p03 << " ";
                            if (!valid(p03))
                                continue;
                            string p04 = s.substr(i+j+k, s.length() - k);
                            //cout << p04 << " ";
                            if (!valid(p04))
                                continue;

                            // valid IP
                            string ip = s;
                            ip.insert(i + j + k, ".");
                            ip.insert(i + j, ".");
                            ip.insert(i, ".");
                            rs.push_back(ip);
                        }
                    }
                }
            }
        }
        return rs;
    }
};

int main()
{
    string s = "101023";
    Solution sln;
    cout << sln.restoreIpAddresses(s).size() << endl;

    return 0;
}
