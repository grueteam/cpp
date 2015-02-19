#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  //string vv[4];
  vector<string> v;
  v.push_back("s1");
  v.push_back("s2");
  v.push_back("s3");
  v.push_back("s4");

  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;

  v.erase(v.begin() + 2);
  cout << endl;

  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}
