
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    double doOperator(double a, double b, int op) {
        switch (op)
        {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3: {
            if (b == 0)
                return INT_MAX;
            return a / b;
        }
        case 4:
            return b - a;
        case 5: {
            if (a == 0)
                return INT_MAX;
            return b / a;
        }
        default:
            break;
        }
        return 0;
    }

    bool judgePoint24(vector<int>& cards) {
        bool rs = false;

        function<void(vector<double>&, int)> Try = [&](vector<double>& remains, int idx) -> void        // the i-th pick (2 cards each)
            {
                if (rs)
                    return;

                if (remains.size() == 1) {
                    if (abs(remains[0] - 24) < 0.01) {      // approx.
                        rs = true;
                    }
                    return;
                }

                // pick 2 last items and try operation
                double a = remains[remains.size() - 1]; remains.pop_back();
                double b = remains[remains.size() - 1]; remains.pop_back();

                for (int i = 0; i < 6; i++) {
                    double c = doOperator(a, b, i);
                    
                    vector<double> prev = remains;
                    remains.push_back(c);
                    sort(remains.begin(), remains.end());

                    do {                            
                        Try(remains, idx + 1);
                    } while (next_permutation(remains.begin(), remains.end()));

                    if (rs)
                        return;
                    remains = prev;
                }

                remains.push_back(b);
                remains.push_back(a);
            };

        sort(cards.begin(), cards.end());
        // try all permutations (different orders)
        do {
            vector<double> remains;
            for (auto& i : cards) {
                remains.push_back(i);
            }
            Try(remains, 0);
            if (rs) {
                return true;
            }
        } while (next_permutation(cards.begin(), cards.end()));

        return false;
    }
};

int main()
{
    Solution sln;
    vector<int> cards = { 3,3,8,8 };
    cout << sln.judgePoint24(cards) << endl;

    return 0;
}
