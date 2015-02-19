// Утиная типизация
// Duck Typing
#include <iostream>

using namespace std;

template <class T>
void utka(T t) {
  cout << "Before" << endl;
  t.Krya(); // Метод "Кря"
  cout << "After" << endl;
}

template <class T>
void sobaka(T t) {
  cout << "Before2" << endl;
  t.Gav(); // Метод "Гав"
  cout << "After2" << endl;
}

struct A {
  void Krya() {
    cout << "Krya!" << endl;
  }
};

struct B {
  void Gav() {
    cout << "Gav!" << endl;
  }
};

struct C {
  void Krya() {
    cout << "Krya!" << endl;
  }
  void Gav() {
    cout << "Gav!" << endl;
  }
};

int main() {
  A a;
  utka(a);
  B b;
  sobaka(b);
  utka(a);

  C c;
  utka(c);
  sobaka(c);

  return 0;
}
