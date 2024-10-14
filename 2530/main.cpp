#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#include <algorithm>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq(nums.begin(), nums.end());

        long long sum = 0;  // Use long long to avoid integer overflow
        int temp;
        for (int i = 0; i < k; i++) {
            sum += pq.top();  // Get the top element from the priority queue

            if (pq.top() % 3 == 0) {
                temp = pq.top() / 3;
            } else {
                temp = pq.top() / 3 + 1;
            }

            pq.pop();  // Remove the top element from the queue
            pq.push(temp);  // Push the updated value back into the queue
        }

        return sum;  // Return the accumulated sum
    }
};

int main() {
    // Example input
    std::vector<int> nums = {10, 20, 30, 40, 50};
    int k = 3;
    float a = 4;

    Solution sol;
    long long result = sol.maxKelements(nums, k);

    std::cout << "Result: " << result << std::endl;  // Output the result

    return 0;
}

