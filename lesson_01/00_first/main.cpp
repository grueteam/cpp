#include <iostream>
#include <cstdlib>

using namespace std; // Пространство имён, чтобы не писать везде std::cin

int main() { // Основная функция
  cout << "Enter two numbers: "; // Выводим на экран
  int a, b; // Объявляем 2 переменные целого типа
  std::cin >> a >> b; // Вводим их с клавиатуры
  std::cout << a << " + " << b << " = " << a + b << std::endl; // Вывод суммы
  system("pause"); // Нажмите любую клавишу...
  return 0; // Программа завершилась удачно, 0 - код возврата
}
