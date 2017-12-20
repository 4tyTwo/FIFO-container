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
  void push(int info); //��������� � �����
  void pop(); //������� ������ �������
  inline element& first() { return *_first; } //�������� ������ �������
  inline int size() { return _size; }
  ~Queue();
private:
  element * _first,*last;
  int _size;
};

