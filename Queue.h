#pragma once
struct  element{
  element* next;
  int info;
};
class Queue
{
public:
  Queue();
  Queue(int info);
  Queue(Queue& list);
  void push(int info); //Добавляем в конец
  void pop(); //удаляем первый элемент
  inline element& first() { return *_first; } //Получаем первый элемент
  inline int size() { return _size; }
  ~Queue();
private:
  element * _first,*last;
  int _size;
};

