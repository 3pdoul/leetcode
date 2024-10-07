#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        // If the sizes are equal, directly compare the strings
        if (sentence1.size() == sentence2.size()) {
            return sentence1 == sentence2;
        }

        std::vector<std::string> s1;
        std::istringstream stream1(sentence1);
        std::string word;
        while (stream1 >> word) {
            s1.push_back(word);
        }

        std::vector<std::string> s2;
        std::istringstream stream2(sentence2);
        while (stream2 >> word) {
            s2.push_back(word);
        }

        if (s1.size() > s2.size()) {
            std::swap(s1, s2);
        }

        int ptr_left = 0;
        int s1_right = s1.size() - 1;
        int s2_right = s2.size() - 1;

        while (ptr_left < s1.size() && s1[ptr_left] == s2[ptr_left]) {
            ptr_left++;
        }

        while (s1_right >= ptr_left && s1[s1_right] == s2[s2_right]) {
            s1_right--;
            s2_right--;
        }
        return (ptr_left > s1_right);
    }
};
int main() {
    Solution solution;
    std::string sentence1 = "My name is Haley";
    std::string sentence2 = "My Haley";

    if (solution.areSentencesSimilar(sentence1, sentence2)) {
        std::cout << "The sentences are similar." << std::endl;
    } else {
        std::cout << "The sentences are not similar." << std::endl;
    }

    return 0;
}