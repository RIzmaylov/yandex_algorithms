#include <iostream>
#include <sstream>

using namespace std;

void UpList() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  int first;
  int x;
  ss >> first;
  bool flag = true;
  while (ss >> x) {
    if (x > first) {
      first = x;
    } else {
      flag = false;
      break;
    }
  }
  if (flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main_A()
{
  UpList();
  return 0;
}
