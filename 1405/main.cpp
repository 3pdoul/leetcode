#include <queue>
#include <tuple>
#include <string>
class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        std::priority_queue<std::pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        std::string result = "";
        while (!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();
            
            if (result.size() >= 2 && result.back() == char1 && result[result.size()-2] == char1) {
                if (pq.empty()) break; 
                
                auto [count2, char2] = pq.top();
                pq.pop();
                
                result += char2;
                count2--;
                
                if (count2 > 0) pq.push({count2, char2});
                
                pq.push({count1, char1});
            } else {
                result += char1;
                count1--;
                
                if (count1 > 0) pq.push({count1, char1});
            }
        }
        
        return result;
    }
};

#include <iostream>
#include <string>

int main() {
    Solution solution;

    // Test case 1
    int a = 1, b = 1, c = 7;
    std::string result1 = solution.longestDiverseString(a, b, c);
    std::cout << "Test case 1: " << result1 << std::endl;

    a = 7, b = 1, c = 0;
    std::string result2 = solution.longestDiverseString(a, b, c);
    std::cout << "Test case 2: " << result2 << std::endl; 

    a = 0, b = 0, c = 0;
    std::string result3 = solution.longestDiverseString(a, b, c);
    std::cout << "Test case 3: " << result3 << std::endl;  

    a = 5, b = 5, c = 5;
    std::string result4 = solution.longestDiverseString(a, b, c);
    std::cout << "Test case 4: " << result4 << std::endl;  

    return 0;
}
