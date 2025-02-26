
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string tmp;

        while (ss >> tmp) {
            words.push_back(tmp);
        }
        
        string rs;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            rs += words[i];
            if (i != 0)
                rs += " ";
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    cout << sln.reverseWords("  hello world  ") << endl;

    return 0;
}
