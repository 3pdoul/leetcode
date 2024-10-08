#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int res = 0;
        for (auto ch : s) {
            if (ch == '[') {
                res++;
            } else if (res > 0) {
                res--;
            }
        }
        return (res + 1) / 2;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "[]][[]";
    string test2 = "[[[]]][";
    string test3 = "[]";
    string test4 = "]]][[[";
    string test5 = "[[]][]";

    cout << "Minimum swaps for '" << test1 << "': " << solution.minSwaps(test1) << endl; // Expected output: 1
    cout << "Minimum swaps for '" << test2 << "': " << solution.minSwaps(test2) << endl; // Expected output: 1
    cout << "Minimum swaps for '" << test3 << "': " << solution.minSwaps(test3) << endl; // Expected output: 0
    cout << "Minimum swaps for '" << test4 << "': " << solution.minSwaps(test4) << endl; // Expected output: 2
    cout << "Minimum swaps for '" << test5 << "': " << solution.minSwaps(test5) << endl; // Expected output: 0

    return 0;
}