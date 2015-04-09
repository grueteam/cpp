// Зачем нужны get/set методы?
// ---------------------------
// Don’t Repeat Yourself
// http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
#include <iostream>
#include <math.h>

#include "square.h"

using namespace std;

int main() {
  Square s;
  cout << "set side 12" << endl;
  s.setSide(12);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  cout << "set area 100" << endl;
  s.setArea(100);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  return 0;
}
