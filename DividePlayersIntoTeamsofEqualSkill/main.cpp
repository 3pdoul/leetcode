#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        for(auto s: skill) {
            sum += s;
        }
        if ((sum) % (skill.size() / 2) != 0) {
            return -1;
        }
        long long avr = sum / (skill.size() / 2);
        unordered_map<int, int> reps;
        for (auto s: skill) {
            reps[s]++;
        }
        long long res = 0;
        for (auto& r: reps) {
            if (r.first == avr / 2 && avr % 2 == 0) {
                if (r.second % 2 != 0) {
                    return -1;
                } else {
                    for (int i = 0; i < r.second; i++) {
                        res += (r.first * r.first); 
                    }
                }
            } else {
                if (r.second == reps[avr - r.first]) {
                    for (int i = 0; i < r.second; i++) {
                        res += (r.first * (avr - r.first)); 
                    }
                } else {
                    return -1;
                }
            }
        }
        return res / 2;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> skill1 = {3, 6, 3, 6};
    cout << "Test Case 1 Result: " << solution.dividePlayers(skill1) << endl;  // Expected output: 54
    
    // Test Case 2
    vector<int> skill2 = {4, 4, 6, 2};
    cout << "Test Case 2 Result: " << solution.dividePlayers(skill2) << endl;  // Expected output: 40
    
    // Test Case 3
    vector<int> skill3 = {1, 2, 3, 4};
    cout << "Test Case 3 Result: " << solution.dividePlayers(skill3) << endl;  // Expected output: -1
    
    // Test Case 4
    vector<int> skill4 = {5, 5, 5, 5};
    cout << "Test Case 4 Result: " << solution.dividePlayers(skill4) << endl;  // Expected output: -1

    return 0;
}