#ifndef EmployeeTypes_H
#define EmployeeTypes_H

#include <cstddef>
#include <iostream>

template <typename T> 
class SingleLinkedList {
  struct Node {
    T data;
    Node *next;

    // Constructor for Node
    Node(const T &item, Node *nextNode) : data(item), next(nextNode) {}
  };

  Node *head;
  Node *tail;
  size_t num_items;

public:
  // Constructor
  SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

  // Destructor
  ~SingleLinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  // Add item to the front of the list
  void push_front(const T &item) {
    Node *newNode = new Node{item, head};
    head = newNode;
    if (tail == nullptr) {
      tail = newNode;
    }
    num_items++;
  }

  // Add item to the end of the list
  void push_back(const T &item) {
    Node *newNode = new Node{item, nullptr};
    if (tail == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    num_items++;
  }

  // Remove item from the front of the list
  void pop_front() {
    if (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
      num_items--;
      if (head == nullptr) {
        tail = nullptr;
      }
    }
  }

  // Remove item from the end of the list
  void pop_back() {
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
      num_items = 0;
    } else {
      Node *current = head;
      while (current->next != tail) {
        current = current->next;
      }
      delete tail;
      tail = current;
      tail->next = nullptr;
      num_items--;
    }
  }

  // Get the first item in the list
  T &front() { return head->data; }

  // Get the first item in the list (const version)
  const T &front() const { return head->data; }

  // Get the last item in the list
  T &back() { return tail->data; }

  // Get the last item in the list (const version)
  const T &back() const { return tail->data; }

  // Check if the list is empty
  bool empty() const { return num_items == 0; }

  // Insert an item at a specified index
  void insert(size_t index, const T &item) {
    if (index == 0) {
      push_front(item);
    } else if (index >= num_items) {
      push_back(item);
    } else {
      Node *current = head;
      for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
      }
      Node *newNode = new Node{item, current->next};
      current->next = newNode;
      num_items++;
    }
  }

  // Remove an item at a specified index
  bool remove(size_t index) {
    if (index >= num_items) {
      return false;
    }
    if (index == 0) {
      pop_front();
    } else {
      Node *current = head;
      for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
      }
      Node *temp = current->next;
      current->next = temp->next;
      delete temp;
      if (current->next == nullptr) {
        tail = current;
      }
      num_items--;
    }
    return true;
  }

  // Find the index of a given item
  size_t find(const T &item) const {
    Node *current = head;
    size_t index = 0;
    while (current != nullptr) {
      if (current->data == item) {
        return index;
      }
      current = current->next;
      index++;
    }
    return num_items;
  }

  // Display the items in the list
  void displayList() const {
    Node *current = head;
    std::cout << "List: ";
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

// Explicit instantiation of the SingleLinkedList template with int
template class SingleLinkedList<int>;

#endif
