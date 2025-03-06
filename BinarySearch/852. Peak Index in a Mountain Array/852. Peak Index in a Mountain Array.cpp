
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
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n == 3) {
            return 1;
        }
        int left = 0;
        int right = n - 1;
        int rs = 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid > 0 && arr[mid] > arr[mid - 1]) {
                rs = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            cout << " > check mid " << mid << " left " << left << " " << right << endl;
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> arr = { 3,4,5,1 };
    cout << sln.peakIndexInMountainArray(arr) << endl;

    return 0;
}
