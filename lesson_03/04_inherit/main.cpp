#include <iostream>

using namespace std;

class A {
 public: // Доступно всем
  int a;
 protected: // Доступно себе и наследникам
  int forChilds;
 private:  // Доступно только мне
  int privateA;
};

class B : public A {
 public:
  int a;
  int b;
  void method1() {
    a = 1;
    b = 2;
    forChilds = 10;
    A::a = 10;
    B::a = 11;
    // privateA = 1; // Невозможно
  }
};

class C : public B {
 public:
  int c;
};

int main() {
  A a1, a2;
  a1.a = 1;
  B b1;
  b1.a = 2;
  b1.b = 3;
  //b1.forChilds = 5;

  return 0;
}
