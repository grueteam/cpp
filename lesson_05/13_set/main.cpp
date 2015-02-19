#include <iostream>
#include <set> // set - множество
#include <cassert>

using namespace std;

int main() {
  set<int> s;
  s.insert(10);
  assert(s.size() == 1);
  s.insert(5);
  assert(s.size() == 2);
  s.insert(10);
  assert(s.size() == 2);
  s.insert(10);
  assert(s.size() == 2);
  s.insert(10);
  assert(s.size() == 2);

  for(set<int>::iterator i = s.begin();
      i != s.end();
      ++i)
    cout << *i << endl;

  return 0;
}
