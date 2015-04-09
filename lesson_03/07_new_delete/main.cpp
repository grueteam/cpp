// Динамическая память new / delete
// --------------------------------
#include <iostream>

using namespace std;

//-->
struct MyStruct {
  int a, b;
  double d;
};

int main() {
  // Отводим динамическую память
  MyStruct* p = new MyStruct;

  // Освобождаем динамическую память
  delete p;

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000];

  // Освобождаем память
  delete[] intArray;

  return 0;
}
//<--
