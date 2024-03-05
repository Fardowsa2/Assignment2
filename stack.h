#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>

class Stack {
private:
    std::vector<int> num;

public:
    // Add an element to the top of the stack
    void push_front(int value);

    // Remove the top element from the stack
    void pop_front();

    // Calculate the average value of the stack elements
    double average() const;

    // Display the elements of the stack
    void read_stack() const;

    // Check if the stack is empty
    bool empty() const;

    // Get the value of the top element of the stack
    int top() const;

};

#endif // STACK_H
