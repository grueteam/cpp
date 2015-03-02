// Побитовые операции с целыми числами
// -----------------------------------
// Каждый бит как логическая переменная
#include <iostream>

using namespace std;

// Пространства имён
//-->
namespace A {
int a;
}

namespace B {
int a;
}
//<--

//-->
int main() {
  A::a = 1;
  B::a = 2;
  // >> - побитовые сдвиг вправо
  // 101111 -> 001011
  // << - побитовые сдвиг влево
  // 00101111 -> 10111100
  int c = 3 + 5 >> 1;
  // 5 >> 1
  // 101 >> 1 -> 10

  int lp = 10 << 2;

  // Логические операции (побитовые)
  // & - И (AND)
  // 0011 & 0101 => 0001
  // | - ИЛИ (OR)
  // 0011 & 0101 => 0111
  //  0 0  -> 0
  //  0 1  -> 1
  //  1 0  -> 1
  //  1 1  -> 1
  // ^ - Исключающее ИЛИ (XOR) - не равно
  // 0011 & 0101 => 0110
  //  0 0  -> 0
  //  0 1  -> 1
  //  1 0  -> 1
  //  1 1  -> 0

  // ~ - Инверсия (NOT)
  // ~01 => 10
  // 3 = 11
  int k = ~1 & 3; // 01 -> 10
  cout << "k = " << k << endl;

  //c = 2, A::a = 4 + A::b;
  cout << "c = " << c << endl;
  return 0;
}
//<--