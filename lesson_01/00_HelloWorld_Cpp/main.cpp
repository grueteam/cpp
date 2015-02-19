#include <iostream>

using namespace std;

int staticArray[1000];
int staticConsts[3] = {3, 4, 5};

// Статическая
// Динамическая: new / delete, [m/c]alloc / free
// Стек: локальные переменные + вызов функций / методов
int f() {
  f();
}

int main() {
  //f();
  cout << "Hello world!" << endl;
  return 0;
}
