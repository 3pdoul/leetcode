#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


class CustomStack {
public:
    int capacity;
    int top;
    int* data;
    CustomStack(int maxSize) {
        capacity = maxSize;
        data = new int[capacity];
        top = -1;
        
    }
    
    void push(int x) {
        if (top < capacity-1){
            data[++top] = x;
        }
    }
    
    int pop() {
        if (top < 0){
            return -1;
        }
        else {
            return data[top--];
        }
    }
    
    void increment(int k, int val) {
        int min_ptr = std::min(k,top+1);
        for (int i = 0; i < min_ptr; i++){
            data[i] = data[i] + val;
        }
        
    }
};

int main(){
    // Define the sequence of operations and their corresponding inputs
    std::vector<std::string> operations = {
        "CustomStack","push","push","pop",
        "push","push","push",
        "increment","increment",
        "pop","pop","pop","pop"
    };
    
    std::vector<std::vector<int>> inputs = {
        {3},        // CustomStack(3)
        {1},        // push(1)
        {2},        // push(2)
        {},         // pop()
        {2},        // push(2)
        {3},        // push(3)
        {4},        // push(4) - Should be ignored as capacity is 3
        {5,100},    // increment(5, 100)
        {2,100},    // increment(2, 100)
        {},         // pop()
        {},         // pop()
        {},         // pop()
        {}          // pop()
    };

    // Vector to store the outputs
    std::vector<std::string> output;

    // Pointer to the CustomStack object
    CustomStack* stk = nullptr;

    // Iterate through each operation and execute accordingly
    for(int i = 0; i < operations.size(); i++){
        std::string op = operations[i];
        std::vector<int> input = inputs[i];

        if(op == "CustomStack"){
            stk = new CustomStack(input[0]);
            output.push_back("null");
        }
        else if(op == "push"){
            stk->push(input[0]);
            output.push_back("null");
        }
        else if(op == "pop"){
            int res = stk->pop();
            if(res == -1){
                output.push_back("-1");
            }
            else{
                output.push_back(std::to_string(res));
            }
        }
        else if(op == "increment"){
            stk->increment(input[0], input[1]);
            output.push_back("null");
        }
    }

    // Print the output in the required format
    std::cout << "[";
    for(int i = 0; i < output.size(); i++){
        std::cout << (i > 0 ? "," : "") << output[i];
    }
    std::cout << "]" << std::endl;

    // Clean up dynamically allocated memory
    delete stk;

    return 0;
}