#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> count;

        for (auto i : arr) {
            int modValue = ((i % k) + k) % k; 
            count[modValue]++;
        }

        for (const auto& p : count) {
            int remainder = p.first;
            if (remainder == 0) {
                if (p.second % 2 != 0) return false; 
            }
            else if (remainder * 2 == k) {
                if (p.second % 2 != 0) return false; 
            }
            else {
                if (p.second != count[k - remainder]) return false; 
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k1 = 5;
    cout << "Test 1: " << (solution.canArrange(arr1, k1) ? "True" : "False") << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    int k2 = 7;
    cout << "Test 2: " << (solution.canArrange(arr2, k2) ? "True" : "False") << endl;

    vector<int> arr3 = {1, 2, 3, 4, 5, 6};
    int k3 = 10;
    cout << "Test 3: " << (solution.canArrange(arr3, k3) ? "True" : "False") << endl;

    return 0;
}