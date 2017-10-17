#include <cassert>
#include <cs111.h>
#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;


List::Node::Node(const Item& value, Node* previous, Node* next) {
  Value = value;
  Previous = previous;
  Next = next;
}

List::List() {
  Head = NULL;
  currentPosition = NULL;
  len = 0;
}

List::~List() {
  deleteAll(Head);
}

void List::insertBefore(const Item& item) {
  if(Head == NULL) {
    currentPosition = new Node(item);
    Head = currentPosition;
    len++;
  }
  else {
    currentPosition = new Node(item, currentPosition -> Previous, currentPosition);
    if (currentPosition -> Previous != NULL) {
      currentPosition -> Next -> Previous = currentPosition;
      currentPosition -> Previous -> Next = currentPosition;
    }
    else {
      Head = currentPosition;
      currentPosition -> Next -> Previous = currentPosition;
    }
    len++;
  }
}

void List::insertAfter(const Item& item) {
  if(Head == NULL) {
    currentPosition = new Node(item);
    Head = currentPosition;
    len++;
  }
  else {
    currentPosition = new Node(item, currentPosition, currentPosition -> Next);
    if (currentPosition -> Next != NULL) {
      currentPosition -> Next -> Previous = currentPosition;
      currentPosition -> Previous -> Next = currentPosition;
    }
    else {
      currentPosition -> Previous -> Next = currentPosition;
    }
    len++;
  }
}

List::Item List::retrieve() const {
  assert(!empty() && currentDefined());
  return currentPosition -> Value;
        
}

//REVISE REMOVE TO ACCOUNT FOR A SINGLE ITEM LIST OR A LIST WHERE CURRENT POINTS TO THE VALUE BEFORE //ITS END. ***** |UPDATE: REVISED 3/7/17 AT 9:00PM| ******

//REVISE THIS CODE TO SEE IF THIS REMOVE FUNCTION UPDATELY CURRENT POSITION PROPERLY


void List::remove() {
  assert(!empty());
  Node* n1 = NULL;
  Node* n2 = NULL;

  Node* dead = currentPosition;
  if(currentPosition -> Next == NULL) {
    if(currentPosition -> Previous != NULL) {
      n1 = currentPosition -> Previous;
      n1 -> Next = currentPosition -> Next; // after "= sign" can be replaced with NULL
      currentPosition = currentPosition -> Previous;
      delete dead;
      len--;
    }

    else {
      currentPosition = NULL;
      Head = NULL;
      delete dead;
      len--;
    }
  }
  else {
    if(currentPosition -> Previous != NULL) {
      n1 = currentPosition -> Previous;
      n1 -> Next = currentPosition -> Next;
      n2 = currentPosition -> Next;
      n2 -> Previous = currentPosition -> Previous;
      currentPosition = currentPosition -> Next;
      delete dead;
      len--;
    }

    else {
      n2 = currentPosition -> Next;
      n2 -> Previous = currentPosition -> Previous;
      currentPosition = currentPosition -> Next;
      delete dead;
      len--;
    }
  }
  return;
}

void List::head() {
  currentPosition = Head;
}
 
void List::advance() {
  currentPosition = currentPosition -> Next;
}

bool List::currentDefined() const {
  if(currentPosition != NULL)
    return true;
  return false;
}

size_t List::length() const {
  return len;
}

bool List::empty() const {
  if(Head == NULL)
    return true;
  return false;
}

void List::copy(const List& list) {
  assert(!list.empty());
  deleteAll(Head);
  for(Node* h = list.Head; h != NULL; h = h->Next) {
    insertAfter(h->Value);
  }
  head();
  for(Node* p = list.Head; p < list.currentPosition; p = p -> Next) {
    advance();
  }
}

void List::display(ostream& s) const {
  cout << endl;
  for (Node* p = Head; p != NULL; p = p->Next) {
    s << "[" << p->Value << "]" << ",";
  }
  cout << endl;
}

void List::emptyList() {
  deleteAll(Head);
}

void List::deleteAll(Node* front) {
  if (front == NULL){
    Head = NULL;
    currentPosition = NULL;
    len = 0;
    return;
  }

  deleteAll(front->Next);
  delete front;
}

