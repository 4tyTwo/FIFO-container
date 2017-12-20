#include "Queue.h"



Queue::Queue()
{
  _first = last = nullptr;
  _size = 0;
}

Queue::Queue(int info) {
  _first = last = new element;
  _first->info = info;
  _first->next = nullptr;
  _size = 1;
}

Queue::Queue(Queue& list) {
  element* curr , tmp;
  if (list.size()) {
    _first = new element;
    curr = _first;
    tmp = list.first();
    curr->info = tmp.info;
    while (tmp.next) {
      curr->info = tmp.info;
      curr->next = new element;
      tmp = *tmp.next;
    }
    curr->next = nullptr;
    last = curr;
  }
  _size = list.size();
}

void Queue::push(int info) {
  if (!_first) {
    _first = new element;
    _first->next = nullptr;
    _first->info = info;
    last = _first;
    ++_size;
    return;
  }
  last->next = new element;
  last->next->info = info;
  last->next->next = nullptr;
  last = last->next;
  ++_size;
}

void Queue::pop() {
  if (_size == 0)
    return;
  if (_size == 1)
    _first = last = nullptr;
  else
    _first = _first->next;
  --_size;
}

Queue::~Queue()
{
}
