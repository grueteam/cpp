// Домашнее задание - рекурсия
// ---------------------------
//  ЗАДАНИЕ:
// Пользователь вводит натуральное число N.
// Нужно вывести все способы разложить его на слагаемые.
// Способы отличающиеся только
// порядком слагаемых считаются одинаковыми.
// -----------------------
// Например N = 4:
// 4 = 4
// 4 = 3 + 1
// 4 = 2 + 2
// 4 = 2 + 1 + 1
// 4 = 1 + 1 + 1 + 1
#include <iostream>
#include <cmath>

#define MIN(x,y) (x < y) ? x : y

int MIN(int x, int y) {
  return (x < y) ? x : y;
}

/*template <class T>
T MIN(T x,T y){
  return (x < y) ? x : y;
}*/

using namespace std;

const int MAX_N = 10000;

// N - число для разложения
// m - максимальное слагаемое в сумме
void sum(int N, int m) {
  // Цифры
  static int A[MAX_N];
  // Количество
  static int K = 0;

  // Окончание рекурсии
  if(N == 0) {
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

int main() {
  // Вводим число N
  int N;
  cout << "N = ";
  cin >> N;

  // Вывод разложения на слагаемые
  sum(N);

  return 0;
}
