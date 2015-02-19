#include <iostream>

using namespace std;

class A {
 public:
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};

class B : public A {
 public:
  int x = -2;
  void show() {
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};

int main() {
  A a;
  B b;
  a.x = 1;
  a.show();
  b.x = 2;
  b.show();
  return 0;
}
