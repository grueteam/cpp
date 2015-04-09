#include <iostream>

using namespace std;

void f1(int value) {
  value++;
  cout << "f1 = " << value << endl;
}

void f2(int& value) {
  value++;
  cout << "f2 = " << value << endl;
}

void f3(int* value) {
  (*value)++;
  cout << "f3 = " << *value << endl;
}


int main() {

  int value = 1;

  f1(value);
  cout << "after f1 = " << value << endl;

  f2(value);
  cout << "after f2 = " << value << endl;

  f3(&value);
  cout << "after f3 = " << value << endl;


  value = 11;
  // int & - объявляем ссылку
  int& b = value; // b и value - одна и та же переменная
  // только с 2-мя именами
  b = 10; // изменилось value
  value = 12; // изменилось b

  int* ptrA, valueA; // ptrA - указатель, valueA - значение
  valueA = 122;

  ptrA = &value; // Указатель ptrA указывает на
  // переменную value

  // *ptrA и value - одна и та же переменная
  value = 1000; // изменится и *ptrA
  *ptrA = 111; // изменится и value

  int d;
  ptrA = &d;

  return 0;
}
