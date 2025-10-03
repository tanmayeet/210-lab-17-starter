// COMSC-210 || Lab 17 || Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <iostream>
using namespace std;

const int SIZE = 7;
const int MAX_RANDOM = 100;
const float = INSERT_VALUE = 10000;

// Node structure
struct Node {
  float value;
  Node* next;
};

// Function prototypes
Node* addToFront(Node* head, float value);
Node* deleteNode(Node* head, int position);
Node* insertAfter(Node* head, int position, float value);
void deleteList(Node*& head);
void output(Node*);

int main() {
  Node* head = nullptr;

  createList(head, SIZE);

  deleteNodePrompt(head);
  output(head);

  insertNodePrompt(head);
  output(head);

  deleteList(head);
  output(head);

  return 0;
}

Node* addToFront(Node* head, float value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = head;
  return newNode;
}

Node* deleteNode(Node* head, int position) {
  if (!head || position < 1) return head;

  if (position == 1) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  Node* current = head;
  Node* prev = nullptr;
  for (int i = 1; i < position && current; i++) {
    prev = current;
    current = current->next;
  }
  if (current) {
    prev->next = current->next;
    delete current;
  }
  return head;
}

Node* insertAfter(Node* head, int position, float value) {
  if (!head || position < 1) {
    return head;
  }

  Node* current = head;
  for (int i = 1; i < position && current; i++) {
    current = current->next;
  }

  if (current) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = current->next;
    current->next = newNode;
  }

  return head;
}

// deleteList() deletes the entire linked lisst
// arguments: reference to head pointer
// returns: nothing
void deleteList(Node*& head) {
  Node* current = head;
  while (current) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
}

void output(Node* hd) {
  if (!hd) {
    cout << "Empty list.\n";
    return;
  }
  int count = 1;
  Node* current = hd;
  while (current) {
    cout << "[" << count++ << "] " << current->value << endl;
    current = current->next;
  }
  cout << endl;
}