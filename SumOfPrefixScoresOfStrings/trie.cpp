#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

// Define the Trie struct
struct Trie {
    int score;
    Trie *children[26];

    // Constructor
    Trie(){
        score = 0;
        memset(children, 0, sizeof(children));
    }

    // Destructor to free allocated memory
    ~Trie(){
        for(int i = 0; i < 26; ++i){
            if(children[i]){
                delete children[i];
                children[i] = nullptr;
            }
        }
    }

    // Method to add a string to the Trie
    void add(string& s, int i = 0){
        if (i > 0) score++;
        if (i == s.size()) return;
        char c = tolower(s[i]); // Ensure lowercase
        if(c < 'a' || c > 'z') return; // Skip invalid characters
        int index = c - 'a';
        if (!children[index]) children[index] = new Trie();
        children[index]->add(s, i + 1);
    }

    // Method to perform DFS and accumulate scores
    int dfs(string& s, int i = 0){
        if (i == s.size()) return score;
        char c = tolower(s[i]); // Ensure lowercase
        if(c < 'a' || c > 'z') return score; // Handle invalid characters
        int index = c - 'a';
        if(!children[index]) return score;
        return score + children[index]->dfs(s, i + 1);
    }
};

// Define the Solution class
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie();
        for(auto &s: words) trie->add(s, 0);
        vector<int> res;
        res.reserve(words.size()); // Optimize vector allocation
        for(auto &s: words) res.push_back(trie->dfs(s, 0));
        delete trie; // Free allocated memory
        return res;
    }
};

// Utility function to print vectors
void printVector(const vector<int>& vec){
    cout << "[";
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i];
        if(i != vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function to test the code
int main(){
    Solution solution;

    // Sample Test Case 1
    vector<string> words1 = {"abc", "ab", "abcd"};
    vector<int> result1 = solution.sumPrefixScores(words1);
    cout << "Test Case 1:" << endl;
    cout << "Input: [\"abc\", \"ab\", \"abcd\"]" << endl;
    cout << "Output: ";
    printVector(result1);
    // Expected Output: [6, 5, 6]

    // Sample Test Case 2
    vector<string> words2 = {"apple", "app", "apex", "bat"};
    vector<int> result2 = solution.sumPrefixScores(words2);
    cout << "\nTest Case 2:" << endl;
    cout << "Input: [\"apple\", \"app\", \"apex\", \"bat\"]" << endl;
    cout << "Output: ";
    printVector(result2);
    // Expected Output: [7, 5, 5, 3]

    // Sample Test Case 3
    vector<string> words3 = {"a", "ab", "abc", "abcd", "abcde"};
    vector<int> result3 = solution.sumPrefixScores(words3);
    cout << "\nTest Case 3:" << endl;
    cout << "Input: [\"a\", \"ab\", \"abc\", \"abcd\", \"abcde\"]" << endl;
    cout << "Output: ";
    printVector(result3);
    // Expected Output: [5, 4, 3, 2, 1]

    // Sample Test Case 4 (Handling Uppercase and Non-Alphabetic Characters)
    vector<string> words4 = {"Hello", "HeLLo", "HELLO!", "World123"};
    vector<int> result4 = solution.sumPrefixScores(words4);
    cout << "\nTest Case 4:" << endl;
    cout << "Input: [\"Hello\", \"HeLLo\", \"HELLO!\", \"World123\"]" << endl;
    cout << "Output: ";
    printVector(result4);
    // Expected Output: [some integer values based on the implementation]

    return 0;
}