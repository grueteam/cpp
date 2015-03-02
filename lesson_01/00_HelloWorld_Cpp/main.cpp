#include <iostream>

// Виды памяти
// -----------
// * Статическая
// * Стек: локальные переменные + вызов функций / методов
// * Динамическая: new / delete, [m/c]alloc / free

using namespace std;

//-->
// Статическая
int staticArray[1000];
int staticConsts[3] = {3, 4, 5};

int ff() {
  static int count = 0;
}
//<--

// Стек: локальные переменные + вызов функций / методов
//-->
int f() {
  int x = 10;
  f();
}
//<--

int main() {
  // Динамическая: new / delete, [m/c]alloc / free
  //-->

  //<--
  return 0;
}
