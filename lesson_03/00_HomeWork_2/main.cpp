#include <iostream>
#include <cmath>

// Вычисление минимума
//-->
#define MIN(x,y) (x < y) ? x : y

int MIN2(int x, int y) {
  return (x < y) ? x : y;
}

template <class T>
T MIN3(T x, T y) {
  return (x < y) ? x : y;
}
//<--

using namespace std;

const int MAX_N = 10000;

//-->
int NN; // Для разложения

// N - число для разложения
// m - максимальное слагаемое в сумме
void sum(int N, int m) {
  // Слагаемые
  static int A[MAX_N];
  // Количество слагаемых
  static int K = 0;

  // Окончание рекурсии
  if(N == 0) {
    cout << NN << " = ";

    for(int i = 0; i < K - 1; ++i)
      cout << A[i] << " + ";

    cout << A[K - 1] << endl;
    return;
  }

  for(int x = min(N, m); x >= 1; --x) {
    // x - текущее слагаемое
    A[K] = x;
    K++;
    // Сумма уменьшилась на x
    // Максимальное слагаемое - x
    sum(N - x, x);
    // Убираем последнее слагаемое
    K--;
  }
}

void sum(int N) {
  sum(N, N);
}
//<--

//-->
int main() {
  // Вводим число N
  cout << "N = ";
  cin >> NN;

  // Вывод разложения на слагаемые
  sum(NN);

  return 0;
}
//<--
