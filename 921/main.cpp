#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> charStack;

        for (char ch : s) {
            if (!charStack.empty() && ch == ')' && charStack.top() == '(') {
                charStack.pop();
            } else {
                charStack.push(ch);
            }
        }
        return charStack.size();
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string test1 = "())";
    string test2 = "(((";
    string test3 = "()";
    string test4 = "()))((";

    cout << "Test 1: " << test1 << " => " << solution.minAddToMakeValid(test1) << endl;
    cout << "Test 2: " << test2 << " => " << solution.minAddToMakeValid(test2) << endl;
    cout << "Test 3: " << test3 << " => " << solution.minAddToMakeValid(test3) << endl;
    cout << "Test 4: " << test4 << " => " << solution.minAddToMakeValid(test4) << endl;

    return 0;
}