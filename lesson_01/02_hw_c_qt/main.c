// Пример с файлом проекта для Qt
// ------------------------------
#include <stdio.h>

int main(void) { // Основная функция программы (точка входа)
  // Вывод Hello World на экран
  printf("Hello World!\n");

  int varName = 13; // varName - имя переменной, 13 - значение
  int a = 1, b = 2; // Можно сразу создавать и инициализировать 2 переменные
  int c = a + b; // При инициализации можно вычислять выражение

  printf("varName = %d\n", varName); // %d - выводим целое число
  printf("c = %d\n", c);



  return 0;
}

