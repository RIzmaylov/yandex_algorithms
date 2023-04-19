#include <iostream>

using namespace std;

void RootedEquation() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 0 && b != c * c || c < 0) {
    cout << "NO SOLUTION" << '\n';
    return;
  }
  if (a == 0 && b == c * c) {
    cout << "MANY SOLUTIONS" << '\n';
    return;
  }
  if ((c * c - b) % a != 0) {
    cout << "NO SOLUTION" << '\n';
    return;
  }
  cout << (c * c - b) / a << '\n';
}

int main_re()
{
  RootedEquation();
  return 0;
}
