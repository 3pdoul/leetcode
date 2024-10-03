#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) {
            return 0;
        }

        unordered_map<int, int> prefixRemainders;
        prefixRemainders[0] = -1;  
        int currentSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            currentSum = (currentSum + nums[i]) % p;

            int target = (currentSum - totalSum + p) % p;

            if (prefixRemainders.find(target) != prefixRemainders.end()) {
                minLength = min(minLength, i - prefixRemainders[target]);
            }

            prefixRemainders[currentSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {3, 1, 4, 2};
    int p1 = 6;
    cout << "Test Case 1 Result: " << solution.minSubarray(nums1, p1) << endl;  // Expected output: 1 {4}
    
    // Test Case 2
    vector<int> nums2 = {6, 3, 5, 2};
    int p2 = 9;
    cout << "Test Case 2 Result: " << solution.minSubarray(nums2, p2) << endl;  // Expected output: 2 {5,2}
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    int p3 = 3;
    cout << "Test Case 3 Result: " << solution.minSubarray(nums3, p3) << endl;  // Expected output: 0 
    
    // Test Case 4 (custom)
    vector<int> nums4 = {8, 5, 7, 3};
    int p4 = 10;
    cout << "Test Case 4 Result: " << solution.minSubarray(nums4, p4) << endl;  // Expected output: 1 {3}
    
    return 0;
}