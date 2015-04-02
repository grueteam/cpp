// Арифметические операции
// -----------------------
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  //-->
  int a; // "int" - тип переменной, "a" - имя переменной
  cout << "a = ";
  cin >> a;

  cout << "b = ";
  int b;
  cin >> b;

  int a1, a2, a3;

  // * - умножение
  // / - деление
  // % - остаток от деления (взятие по модулю)
  cout << "a + b = " << (a + b) << endl; // В C++ используется endl вместо "\n"
  cout << "a - b = " << (a - b) << endl;
  cout << "a * b = " << (a * b) << endl;
  cout << "a / b = " << (a / b) << endl;
  cout << "a % b = " << (a % b) << endl;

  // 5 / 2 = 2
  // 7 % 4 = 3

  // Пытаемся вызвать несуществующую команду операционной системы
  system("NetTakoiComandy");
  system("pause");
  //<--

  return 0;
}
