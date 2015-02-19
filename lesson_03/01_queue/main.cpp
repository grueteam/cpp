#include <iostream>

using namespace std;

// Очередь
//    -------------------------------
//  <-|  |  |  |  |  |  |  |  |  |  | <-
//    -------------------------------

const int QUEUE_LEN = 10000;

int data[QUEUE_LEN];

int head = 0; // Индекс первого элемента очереди
int tail = 0; // Индекс первой свободной ячейки очереди

// Добавить элемент в конец очереди
void put(int value) {
  data[tail++ % QUEUE_LEN] = value;
  // tail++
}

// Получить значение из начала очереди
int get() {
  return data[head++ % QUEUE_LEN];
}

int main() {

  return 0;
}
