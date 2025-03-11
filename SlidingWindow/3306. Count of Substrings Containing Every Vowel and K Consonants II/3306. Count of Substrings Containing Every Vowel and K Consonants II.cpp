
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        if (n < 5 + k) {
            return false;
        }

        vector<bool> isVowel('z' + 1, false);
        string vowels = "aeiuo";
        for (auto& c : vowels) {
            isVowel[c] = true;
        }

        auto atLeastConsonants = [&](int m) -> int
            {
                int rs = 0;
                int cnt = 0;        // count consonants
                int l = 0;
                unordered_map<char, int> freq;
                for (int r = 0; r < n; r++) {
                    char c = word[r];
                    if (isVowel[c]) {
                        freq[c]++;
                    }
                    else {
                        cnt++;
                    }
                    //cout << " > add char " << c << " freqs " << freq.size() << " cnt " << cnt << endl;

                    // all substrings with extension from r -> end of 'word' are valid
                    while (freq.size() == 5 && cnt >= m) {
                        //cout << "   > valid substring " << word.substr(l, r - l) << endl;
                        rs += n - r;

                        // move left
                        char d = word[l];
                        if (isVowel[d]) {
                            freq[d]--;
                            if (freq[d] == 0) {
                                freq.erase(d);
                            }
                        }
                        else {
                            cnt--;
                        }
                        l++;
                    }
                }
                //cout << " > at least " << m << ": " << rs << endl;
                return rs;
            };

        return atLeastConsonants(k) - atLeastConsonants(k + 1);
    }
};

int main()
{
    Solution sln;
    cout << sln.countOfSubstrings("ieaouqqieaouqq", 1) << endl;

    return 0;
}
