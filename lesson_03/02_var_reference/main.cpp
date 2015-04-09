// Значение / ссылка / указатель
// -----------------------------
#include <iostream>

using namespace std;

#define SHOW(x) cout << __FUNCTION__ << ": " << #x << " = " << x << endl;

// Передача параметров
//-->
// По значению
void f1(int i) {
  i++;
  SHOW(i)
}

// По ссылке (только C++)
void f2(int& i) {
  i++;
  SHOW(i)
}

// По указателю
void f3(int* i) {
  (*i)++;
  SHOW(*i)
}

int main() {
  int i = 0;
  SHOW(i);

  f1(i);
  SHOW(i);
  f2(i);
  SHOW(i);
  f3(&i);
  SHOW(i);

  return 0;
}
//<--
