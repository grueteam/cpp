// Оператор присваивания. Операторы и их приоритеты. Скобки
// --------------------------------------------------------
// Операции отношения: (<, <=, >, >=, ==, !=). Логические операции (&& и ||).

// Цепочки операторов
// ------------------
#include <iostream>


using namespace std;

int main() {
  // Объявляем 2 переменные
  // целого типа
  //-->
  int a = 3, b = 5;
  //<--

  // Сокращённая форма оператора присваивания
  // Сокращённые операторы (+=, -=, *=, /=, %=, ++, --).
  a = a * b; /* <=> */
  a *= b;
  a = a + b; /* <=> */
  a += b;
  a = a - b; /* <=> */
  a -= b;
  a = a / b; /* <=> */
  a /= b;
  a = a % b; /* <=> */
  a %= b;

  // Инкремент
  a++;
  a = a + 1; // Постфиксная форма
  ++a; // Префиксная форма

  int N = 10;
  int M = N++;
  cout << "N = " << N << endl;
  cout << "M = " << M << endl;

  a = 1;
  b = ++++++a;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  --++++++----b;
  --++--++----b;
  --++--++----b;
  --++--++----b;
  ++++--++----b;

  a++;
  ++a;
  // Декремент
  a--;
  --a;

  a = 20;
  int c = (++a)++;
  cout << "c = " << c << " a = " << a << endl;

  a += b += c = 2; // PL/1

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  // Пенять значение 2-х переменных местами
  // без использования 3-ей (промежуточной)
  a = 34634;
  b = -684;
  cout << "a = " << a << "  b = " << b << endl;

  a ^= b ^= a ^= b;

  cout << "a = " << a << "  b = " << b << endl;

  a = 2;
  b = 3;
  cout << "a==b " << (a == b) << endl;

  // a = &p++ + (--a + ++b)

  //   c = {     1, 2,
  //          3, 5, 7, 10,
  //          7, 20, 2, 3,
  //             7, 20    }
  return 0;
}
