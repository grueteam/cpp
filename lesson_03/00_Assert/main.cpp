// Утверждения: assert
// -------------------
// Разработка через тестированиe
// (TDD - Test Driven Development).
//
// Разработка через тестирование (test-driven development, TDD) -
// техника разработки программного обеспечения,
// которая основывается на повторении очень коротких циклов разработки:
// * сначала пишется **тест**, покрывающий желаемое изменение,
// * затем пишется **код**, который позволит пройти тест,
// * и под конец проводится **рефакторинг** нового кода.
#include <iostream>
#include <assert.h>

using namespace std;

//-->
long long fact(int n) {
  assert(n >= 1);

  if(n >= 3)
    return n * fact(n - 1);

  return n;
}
//<--

int main() {
  // Автоматические тесты
  //-->
  assert( fact(1) == 1 );
  assert( fact(2) == 2 );
  assert( fact(3) == 1 * 2 * 3 );
  assert( fact(4) == 1 * 2 * 3 * 4 );
  assert( fact(5) == 1 * 2 * 3 * 4 * 5 );
  fact(0);
  //<--

  // Ручное тестирование функции:
  //-->
  int N;
  cin >> N;
  cout << "fact(" << N << ") = " << fact(N) << endl;

  return 0;
  //<--
}
