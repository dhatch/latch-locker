#ifndef HASHTABLE_TLINKEDLIST_H
#define HASHTABLE_TLINKEDLIST_H

#include "TNode.h"

template <typename T>
class TLinkedList
{

public:
  TNode<T>* head;
  TNode<T>* tail;
  int isize;

  TLinkedList() {
    head = NULL;
    tail = NULL;
    isize = 0;
  }

  void append(TNode<T> *n);
  void prepend(TNode<T> *n);
  void remove(TNode<T> *n);
  int size();

  /**
   * @return True if the list is empty.
   */
  bool empty();
};

template <class T>
void TLinkedList<T>::append(TNode<T> *n) {
  if (head == NULL) {
    head = n;
    tail = n;
    isize = 1;
  } else {
    tail->next = n;
    n->prev = tail;
    n->next = NULL;
    tail = n;
    isize++;
  }
}
template <class T>
void TLinkedList<T>::prepend(TNode<T> *n) {
  if (head == NULL) {
    head = n;
    tail = n;
    isize = 1;
  } else {
    head->prev = n;
    n->next = head;
    head = n;
    isize++;
  }
}

template <class T>
void TLinkedList<T>::remove(TNode<T> *n) {
  if (n == head)
    head = n->next;
  if (n == tail)
    tail = n->prev;
  if (n->next != NULL)
    n->next->prev = n->prev;
  if (n->prev != NULL)
    n->prev->next = n->next;
  isize--;
}

template <class T>
int TLinkedList<T>::size() {
  return isize;
}

template <class T>
bool TLinkedList<T>::empty() {
  return isize == 0;
}

#endif
