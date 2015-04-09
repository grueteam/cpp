// C++
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

using namespace std;

int main() {
  // Вывод в консоль по-русски:
  //-->
  //setlocale(LC_ALL, "Russian_Russia.65001");
  setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
  //<--

  int a = 2;
  int b = 3;
  int c = a + b;

  printf("Это моя первая программа!\n");

  cout << a << "+" << b << "=" << c << endl;

  char buf[100];
  cin >> buf;
  cout << "===========\n";
  cout << buf;

  return 0;
}
