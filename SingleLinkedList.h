#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <cstddef>

template <typename T> 
class SingleLinkedList {
private:
  // Node structure to represent each element in the list
  struct Node {
    T data;     // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with data and next pointer
    Node(const T &item, Node *nextNode) : data(item), next(nextNode) {}
  };

  Node *head;     // Pointer to the first node in the list
  Node *tail;     // Pointer to the last node in the list
  size_t num_items; // Number of items in the list

public:
  // Constructor
  SingleLinkedList();

  // Destructor
  ~SingleLinkedList();

  // Add an item to the front of the list
  void push_front(const T &item);

  // Add an item to the end of the list
  void push_back(const T &item);

  // Remove an item from the front of the list
  void pop_front();

  // Remove an item from the end of the list
  void pop_back();

  // Get the first item in the list
  T &front();

  // Get the first item in the list (const version)
  const T &front() const;

  // Get the last item in the list
  T &back();

  // Get the last item in the list (const version)
  const T &back() const;

  // Check if the list is empty
  bool empty() const;

  // Insert an item at a specified index
  void insert(size_t index, const T &item);

  // Remove an item at a specified index
  bool remove(size_t index);

  // Find the index of a given item
  size_t find(const T &item) const;

  // Display the items in the list
  void displayList() const;
};

#endif

