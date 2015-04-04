#include <iostream>

// Виды памяти
// -----------
// * Статическая
// * Стек: локальные переменные + вызов функций / методов
// * Динамическая: new / delete, [m/c]alloc / free

using namespace std;

// *Статическая* память: глобальные переменные
//-->
int staticArray[1000];
int staticConsts[3] = {3, 4, 5};
//<--

// Переменные с модификатором static.
// Переменная *count* видна только внутри функции ff,
// но при этом сохраняет своё значение между вызовами ff
//-->
int ff() {
  static int count = 0;
}
//<--

// *Стек*: локальные переменные + вызов функций / методов
//-->
int f() {
  int x = 10; // в стеке
  f();
}
//<--

int main() {
  // *Динамическая*: new / delete, [m/c]alloc / free
  //-->

  //<--
  return 0;
}