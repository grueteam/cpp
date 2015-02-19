#include <iostream>
#include <vector>

using namespace std;

template <class T>
void show(vector<T> a) {
  for(int i = 0; i < a.size() - 1; ++i)
    cout << a[i] << ", ";

  cout << a[a.size() - 1] << endl;
}

int main() {
  vector<int> v = {2, 3, 4};
  show(v);
  v.push_back(6);
  show(v);
  v.erase(v.begin() + 2);
  show(v);

  vector<double> d = {3.4, 22.3, 3.3};
  show(d);
  return 0;
}
