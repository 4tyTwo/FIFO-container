#include "Queue.h"
#include"TQueue.h"
int main() {
  TQueue<int> list(3);
  TQueue<int> list1(list);
  list.push(5);
  list1.pop();
  list.first().info = 88;
  return 1;
}