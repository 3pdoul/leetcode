#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
int minLength(string s) {
    stack<char> charStack;

    for (char ch : s) {
        if (!charStack.empty() && 
            ((charStack.top() == 'C' && ch == 'D') || 
             (charStack.top() == 'A' && ch == 'B'))) {
            charStack.pop(); 
        } else {
            charStack.push(ch); 
        }
    }

    return charStack.size();
}
};
int main() {
    string input = "ABACD"; 
    Solution test;
    int result = test.minLength(input);
    cout << "Minimum string length after removals: " << result << endl;
    return 0;
}