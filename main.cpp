/*
Name: Fardowsa Muhumed
Due date: 03/04/2024
Section: Tu/Thu 4:00 pm - 5:15 pm
Assignment: 2
*/

#include "SingleLinkedList.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  // Part 1: Single Linked List Operations
  SingleLinkedList<int> myList;

  // Display header for the Single Linked List operations
  std::cout << "Question # 1 \n" << std::endl;
  std::cout << "------------------\n" << std::endl;

  // Push some elements onto the Single Linked List
  myList.push_front(5);
  myList.displayList();
  std::cout << std::endl;

  myList.push_front(15);
  myList.displayList();
  std::cout << std::endl;

  myList.push_back(25);
  myList.displayList();
  std::cout << std::endl;

  myList.displayList();

  // Remove elements from the Single Linked List
  myList.pop_front();
  myList.pop_back();

  myList.displayList();

  // Insert an element at a specific position in the Single Linked List
  myList.insert(1, 15);

  myList.displayList();

  // Remove an element from a specific position in the Single Linked List
  myList.remove(0);

  myList.displayList();

  // Find an element in the Single Linked List
  int item = 40;
  size_t index = myList.find(item);
  if (index != myList.find(item)) {
    std::cout << "Item " << item << " found at index " << index << std::endl;
  } else {
    std::cout << "\nItem " << item << " not found" << std::endl;
  }

  std::cout << std::endl;
  std::cout << std::endl;

  // Part 2: Stack Operations
  // Display header for the Stack operations
  std::cout << "Question # 2\n" << std::endl;
  std::cout << "------------------\n" << std::endl;

  // Create a stack object
  Stack stack;

  // Check if the stack is empty
  std::cout << "Is stack empty? " << stack.empty() << std::endl;

  // Push elements onto the stack
  std::cout << "Pushing elements onto the stack..." << std::endl;
  stack.push_front(5);
  stack.push_front(10);
  stack.push_front(15);
  stack.read_stack();

  // Remove an element from the stack
  std::cout << "\nRemoving an element from the stack..." << std::endl;
  stack.pop_front();
  stack.read_stack();

  // Get the top element of the stack
  std::cout << "\nTop of the stack: " << stack.top() << std::endl;

  // Calculate the average value of the stack elements
  std::cout << "\nAverage value of the stack elements: " << stack.average() << std::endl;

  return 0;
}
