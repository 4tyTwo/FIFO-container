#pragma once
template<typename T>
class TQueue
{
public:
  struct  element {
    element* next;
    T info;
  };
  TQueue() {
    _first = last = nullptr;
    _size = 0;
  }
  TQueue(TQueue& list) {
    element* curr, tmp;
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
  TQueue(T info) {
    _first = last = new element;
    _first->info = info;
    _first->next = nullptr;
    _size = 1;
  }
  void push(T info) { //Добавляем в конец
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
  void pop(){ //удаляем первый элемент
    if (_size == 0)
      return;
    if (_size == 1)
      _first = last = nullptr;
    else
      _first = _first->next;
    --_size;
  }
  inline element& first() { return *_first; } //Получаем первый элемент
  inline int size() { return _size; }
  ~TQueue() {
  }
private:
  element * _first, *last;
  int _size;
};

