#include <iostream>

using namespace std;

// По ссылке
void f(int& i) {
  i++;
}

// По указателю
void f(int* i) {
  (*i)++;
}

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
