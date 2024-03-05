#include "stack.h"

void Stack::push_front(int value) {
    num.push_back(value);
}

double Stack::average() const {
    if (empty()) {
        return -111; // Return a sentinel value to indicate an empty stack
    }
    double sum = 0;
    for (int i = 0; i < num.size(); i++) {
        sum += num[i];
    }
    return sum / num.size();
}

void Stack::read_stack() const {
    std::cout << "Stack: ";
    for (int i = 0; i < num.size(); i++) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::pop_front() {
    if (!empty()) {
        num.pop_back();
    }
}

bool Stack::empty() const {
    return num.empty();
}

int Stack::top() const {
    if (empty()) {
        return -111; // Return a sentinel value to indicate an empty stack
    }
    return num.back();
}
