
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int N = 1e6;
    vector<bool> primes = vector<bool>(N + 1, true);

    void sieve() {
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= N; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    int splitPrimes(const string& str) {
        // dp(i, state)
        // if state is NOT prime => dp(i + 1, state + str[i])
        // else => dp(i + 1, state + str[i]) + dp(i + 1, str[i])
        // base case :  i == n
        //              state starts with '0'

        sieve();
        int n = str.length();

        map<pair<int, string>, int> m;

        function<int(int, string&)> dp = [&](int i, string& state) -> int
            {
                bool p = primes[stoi(state)];
                if (i == n) {
                    return p ? 1 : 0;
                }
                if (state[0] == '0')
                    return 0;

                pair<int, string> key = { i, state };
                if (m.count(key))
                    return m[key];

                string tmp = state + str[i];
                int rs = dp(i + 1, tmp);
                
                if (p) {
                    string tmp2 = str.substr(i, 1);
                    rs += dp(i + 1, tmp2);
                }
                return m[key] = rs;
            };

        string s = str.substr(0, 1);
        int ans = dp(1, s);

        return ans;
    }
};

int main()
{
    Solution sln;
    //cout << sln.splitPrimes("11373") << endl;
    //cout << sln.splitPrimes("011") << endl;
    //cout << sln.splitPrimes("1234") << endl;
    //cout << sln.splitPrimes("113") << endl;
    cout << sln.splitPrimes("2357") << endl;

    return 0;
}
